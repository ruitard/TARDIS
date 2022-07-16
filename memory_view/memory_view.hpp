#pragma once

#include <cstdint>
#include <cstddef>

namespace memory_view {

class v1 {
public:
    constexpr v1(const uint8_t *data, size_t size) noexcept : m_size{size}, m_data{data} {}
    constexpr size_t size() const noexcept { return this->m_size; }
    const uint8_t &operator[](size_t pos) const noexcept;
private:
    const uint8_t *m_data;
    size_t m_size;
};

class v2 {
public:
    constexpr v2(const uint8_t *data, size_t size) noexcept : m_size{size}, m_data{data} {}
    constexpr size_t size() const noexcept { return this->m_size; }
    constexpr const uint8_t &operator[](size_t pos) const noexcept {
        return *(this->m_data + pos);
    }
private:
    const uint8_t *m_data;
    size_t m_size;
};

}