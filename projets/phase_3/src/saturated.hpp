#ifndef SATURATED_HPP
#define SATURATED_HPP

#include <cstdint>

constexpr uint16_t saturated(int new_value) {
    if (new_value < 0) {
        return 0;
    } else if (new_value > UINT16_MAX) {
        return UINT16_MAX;
    } else {
        return new_value;
    }
}
#endif