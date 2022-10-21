#include <iostream>
#include <string>
#include <variant>
#include <unordered_map>
#include <optional>

#include <lua.hpp>

template <class... Ts> struct overloaded : Ts... {
    using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

class LuaExtension {
public:
    struct Context {
        using value_type = std::variant<bool, int64_t, double, std::string, lua_CFunction>;
        std::unordered_map<std::string, value_type> table;
        value_type &operator[](const std::string &key) { return table[key]; }
    };

public:
    explicit LuaExtension(const std::string &ext_file) {
        lu = luaL_newstate();
        luaL_openlibs(lu);

        luaL_dofile(lu, ext_file.c_str());

        luaL_newmetatable(lu, metatable_name);
        lua_pushcfunction(lu, meta_index_method);
        lua_setfield(lu, -2, "__index");
        lua_pushcfunction(lu, meta_new_index_method);
        lua_setfield(lu, -2, "__newindex");

        lua_pop(lu, 1);
    }
    ~LuaExtension() { lua_close(lu); }

    auto invoke(const std::string &func, Context &ctx) {
        ctx["print"] = ctx_print_method;

        lua_getglobal(lu, func.c_str());
        static_cast<CtxWrap *>(lua_newuserdata(lu, sizeof(CtxWrap)))->ctx = &ctx;
        luaL_setmetatable(lu, metatable_name);

        lua_pcall(lu, 1, 1, 0);

        std::optional<int> ret{};
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

        auto &ctx = *(static_cast<CtxWrap *>(luaL_checkudata(L, 1, metatable_name))->ctx);
        std::string key = luaL_checkstring(L, 2);
        if (!ctx.table.contains(key)) {
            lua_pushnil(L);
            return 1;
        }
        const auto &value = ctx.table[key];
        std::visit(overloaded{[&L](auto arg) { lua_pushnil(L); }, [&L](bool arg) { lua_pushboolean(L, arg); },
                              [&L](int64_t arg) { lua_pushinteger(L, arg); },
                              [&L](double arg) { lua_pushnumber(L, arg); },
                              [&L](const std::string &arg) { lua_pushstring(L, arg.c_str()); },
                              [&L](lua_CFunction arg) { lua_pushcfunction(L, arg); }},
                   value);
        return 1;
    }
    static int meta_new_index_method(lua_State *L) {
        luaL_checkversion(L);

        auto &ctx = *(static_cast<CtxWrap *>(luaL_checkudata(L, 1, metatable_name))->ctx);
        std::string key = luaL_checkstring(L, 2);
        switch (lua_type(L, 3)) {
        case LUA_TNIL: ctx.table.erase((key)); break;
        case LUA_TBOOLEAN: ctx.table[key] = bool(lua_toboolean(L, 3)); break;
        case LUA_TNUMBER:
            if (lua_isinteger(L, 3)) {
                ctx.table[key] = lua_tointeger(L, 3);
            } else {
                ctx.table[key] = lua_tonumber(L, 3);
            }
            break;
        case LUA_TSTRING: ctx.table[key] = std::string(lua_tostring(L, 3)); break;
        default: break;
        }
        return 0;
    }
    static int ctx_print_method(lua_State *L) {
        luaL_checkversion(L);
        auto &ctx = *(static_cast<CtxWrap *>(luaL_checkudata(L, 1, metatable_name))->ctx);
        for (const auto &[key, value] : ctx.table) {
            std::cout << key << '\t';
            std::visit(overloaded{[&L](auto arg) { std::cout << arg << std::endl; },
                                  [&L](bool arg) { std::cout << std::boolalpha << arg << std::endl; },
                                  [&L](lua_CFunction arg) { std::cout << "function" << std::endl; }},
                       value);
        }
        return 0;
    }
};

int main() {
    LuaExtension::Context context;

    LuaExtension le("extension.lua");
    le.invoke("Activate", context);

    context["x_delta"] = -1.0;
    context["y_delta"] = 0.5;
    le.invoke("MoveX", context);
    le.invoke("MoveY", context);

    context["damage"] = 10;
    le.invoke("Attacked", context);

    le.invoke("Deactivate", context);
    return 0;
}