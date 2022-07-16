#include <iostream>

#include "memory_view.hpp"

namespace memory_view {
    const uint8_t &v1::operator[](size_t pos) const noexcept {
        return *(this->m_data + pos);
    }
}