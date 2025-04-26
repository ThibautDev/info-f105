#include "Saturated.hpp"


uint16_t saturated(int new_value) {
    // Converts int to a bounded unsigned 16-bit int

    if (new_value < 0) {
        return 0;
    } else if (new_value > UINT16_MAX) {
        return UINT16_MAX;
    } else {
        return new_value;
    }
}