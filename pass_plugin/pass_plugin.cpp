#include <iostream>

#include "pass.hpp"

class HelloPass : public Pass {
public:
    void operator()() override { std::cout << "hahaha" << std::endl; }
};

static RegisterPass<HelloPass> _("hello");
