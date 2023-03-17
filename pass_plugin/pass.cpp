#include "pass.hpp"

PassRegistry *PassRegistry::get_pass_registry() {
    static PassRegistry PassRegistryObj;
    return &PassRegistryObj;
}

void PassRegistry::register_pass(const PassInfo &pi) {
    std::lock_guard<std::mutex> _(lock);
    pass_map[pi.get_pass_name()] = pi.create_pass(); //<- 注意不要有同名的 pass
}

void PassRegistry::unregister_pass(const PassInfo &pi) {
    std::lock_guard<std::mutex> _(lock);
    pass_map.erase(pi.get_pass_name());
}

Pass &PassRegistry::invoke(const std::string &pass_name) const {
    std::lock_guard<std::mutex> _(lock);
    return *(pass_map.at(pass_name));
}