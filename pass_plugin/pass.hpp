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

class PassRegistry {
public:
    PassRegistry() = default;
    ~PassRegistry() = default;

    static PassRegistry *get_pass_registry();

    void register_pass(const std::string &name, std::unique_ptr<Pass> &&pass);
    void unregister_pass(const std::string &name);
    Pass &invoke(const std::string &pass_name) const; //<- thread unsafe

private:
    mutable std::mutex lock;
    std::unordered_map<std::string, std::unique_ptr<Pass>> pass_map;
};

template <typename PassType> class RegisterPass {
    std::string pass_name;

public:
    explicit RegisterPass(const std::string &name) : pass_name{name} {
        PassRegistry::get_pass_registry()->register_pass(pass_name, std::make_unique<PassType>());
    }
    ~RegisterPass() { PassRegistry::get_pass_registry()->unregister_pass(pass_name); }
};