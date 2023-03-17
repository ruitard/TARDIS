#pragma once

#include <string>
#include <unordered_map>
#include <mutex>
#include <memory>

class Pass {
public:
    Pass() = default;
    Pass(const Pass &) = delete;
    Pass &operator=(const Pass &) = delete;
    virtual ~Pass() = default;
    virtual void operator()() = 0;
};

class PassInfo {
public:
    using PassCtor_t = std::unique_ptr<Pass> (*)();

private:
    std::string pass_name;
    PassCtor_t pass_ctor = nullptr;

public:
    PassInfo(const std::string &name, PassCtor_t normal) : pass_name{name}, pass_ctor{normal} {}
    PassInfo(const PassInfo &) = delete;
    PassInfo &operator=(const PassInfo &) = delete;

    std::string get_pass_name() const { return pass_name; }
    std::unique_ptr<Pass> create_pass() const { return pass_ctor(); }
};

class PassRegistry {
public:
    PassRegistry() = default;
    ~PassRegistry() = default;

    static PassRegistry *get_pass_registry();

    void register_pass(const PassInfo &pi);
    void unregister_pass(const PassInfo &pi);
    Pass &invoke(const std::string &pass_name) const; //<- thread unsafe

private:
    mutable std::mutex lock;
    std::unordered_map<std::string, std::unique_ptr<Pass>> pass_map;
};

template <typename PassName> struct RegisterPass : public PassInfo {
    // Register Pass using default constructor...
    RegisterPass(const std::string &pass_name) :
        PassInfo(pass_name,
                 PassInfo::PassCtor_t([]() -> std::unique_ptr<Pass> { return std::make_unique<PassName>(); })) {
        PassRegistry::get_pass_registry()->register_pass(*this);
    }
    ~RegisterPass() { PassRegistry::get_pass_registry()->unregister_pass(*this); }
};