#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <functional>

#include "memory_view.hpp"

constexpr unsigned long long operator"" _MB(unsigned long long mb) { return mb * (1 << 20); }

volatile uint32_t sink{}; // ensures a side effect

void sum1(const memory_view::v1 &view1) {
    uint32_t sum = 0;
    for (size_t i = 0; i < view1.size(); i++) {
        sum += view1[i];
    }
    sink = sum;
}

void sum2(const memory_view::v2 &view2) {
    uint32_t sum = 0;
    for (size_t i = 0; i < view2.size(); i++) {
        sum += view2[i];
    }
    sink = sum;
}

int main(int argc, const char *argv[]) {
    std::vector<uint8_t> buffer(10_MB); 
    std::iota(buffer.begin(), buffer.end(), argc);

    auto benchmark = [](auto fun, auto rem) {
        const auto start = std::chrono::steady_clock::now();
        for (auto i = 0; i != 100; ++i) {
            fun();
        }
        const std::chrono::duration<double, std::milli> diff = std::chrono::steady_clock::now() - start;
        std::cout << "Time: " << std::fixed << std::setprecision(4) << diff.count() << "ms " << rem << std::endl;
    };

    const memory_view::v1 view1(buffer.data(), buffer.size());
    const memory_view::v2 view2(buffer.data(), buffer.size());
    sum1(view1);sum2(view2);

    benchmark(std::bind(sum1, std::cref(view1)), "memory_view::v1");
    benchmark(std::bind(sum2, std::cref(view2)), "memory_view::v2");

    return 0;
}