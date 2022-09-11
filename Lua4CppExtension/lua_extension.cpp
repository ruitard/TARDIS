#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <memory>
#include <string_view>
#include <unordered_map>

#include <lua.hpp>

template <class... Ts> struct overloaded : Ts... {
    using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

class LuaExtension {
public:
    struct Context {
        using value_type = std::variant<int64_t, double, std::string, lua_CFunction>;
        std::unordered_map<std::string, value_type> table;
    };

public:
    explicit LuaExtension(const std::string &ext_file) {
        lu = luaL_newstate();
        luaL_openlibs(lu);

        luaL_dofile(lu, ext_file.c_str());

        luaL_newmetatable(lu, metatable_name);
        lua_pushcfunction(lu, meta_index_method);
        lua_setfield(lu, -2, "__index");
        lua_pop(lu, 1);
    }
    ~LuaExtension() { lua_close(lu); }

    int activate(const std::unique_ptr<Context> &ctx) {
        lua_getglobal(lu, "Activate");
        static_cast<CtxWrap *>(lua_newuserdata(lu, sizeof(CtxWrap)))->ctx = ctx.get();
        luaL_setmetatable(lu, metatable_name);

        lua_pcall(lu, 1, 1, 0);

        int ret = -1;
        if (lua_isinteger(lu, -1)) {
            ret = lua_tointeger(lu, -1);
        }
        lua_pop(lu, 1);
        return ret;
    }

private:
    lua_State *lu{nullptr};
    struct CtxWrap {
        Context *ctx;
    };
    static constexpr const char metatable_name[] = "context";
    static int meta_index_method(lua_State *L) {
        luaL_checkversion(L);

        auto &ctx = *(static_cast<CtxWrap *>(luaL_checkudata(L, 1, "context"))->ctx);
        std::string key = luaL_checkstring(L, 2);
        if (!ctx.table.contains(key)) {
            lua_pushnil(L);
            return 1;
        }
        const auto &value = ctx.table[key];
        std::visit(overloaded{[&L](auto arg) { lua_pushnil(L); }, [&L](int64_t arg) { lua_pushinteger(L, arg); },
                              [&L](double arg) { lua_pushnumber(L, arg); },
                              [&L](const std::string &arg) { lua_pushstring(L, arg.c_str()); },
                              [&L](lua_CFunction arg) { lua_pushcfunction(L, arg); }},
                   value);
        return 1;
    }
};

int main() {
    auto ctx = std::make_unique<LuaExtension::Context>();
    ctx->table["age"] = 24;
    ctx->table["name"] = "Alice";
    ctx->table["score"] = 3.14;
    ctx->table["call"] = [](lua_State *) -> int {
        std::cout << "host call" << std::endl;
        return 0;
    };
    LuaExtension le("extension.lua");
    int ret = le.activate(ctx);
    std::cout << "ret: " << ret << std::endl;
    return 0;
}