#include <iostream>

#include "pass.hpp"

int main() {
    PassRegistry::get_pass_registry()->invoke("hello")();
    return 0;
}