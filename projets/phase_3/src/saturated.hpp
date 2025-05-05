#ifndef SATURATED_HPP
#define SATURATED_HPP

#include <cstdint>

constexpr uint16_t saturated(int new_value) {
    /*
    Return a 'uint16_t'
    */

    if (new_value < 0) {
        // Make sure it doesn't underflow 
        return 0;
    } else if (new_value > UINT16_MAX) {
        // Make sure it doesn't overflow 
        return UINT16_MAX;
    } else {
        // Return the proper value if it's right
        return new_value;
    }
}
#endif