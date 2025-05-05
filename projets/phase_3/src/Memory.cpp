#include "Memory.hpp"


uint16_tMemoryReference& uint16_tMemoryReference::operator=(uint16_t value) {
    /*
    Apply change to two 'uint8_t' cells as it was an 'uint16_t'
    */

    *lower8 = value & 0xff;
    *upper8 = value >> 8;
    
    return *this;
};

uint16_tMemoryReference::operator uint16_t() const {
    /*
    Return the value from two 'uint8_t' cells as it was an 'uint16_t'
    */

    return *lower8 + (*upper8 << 8);
}


uint16_tMemoryReference Memory::operator[](uint8_t address){
    /*
    Return an 'uint16_tMemoryReference' for double overloading
    */

    return uint16_tMemoryReference(MEM, address);
}

void Memory::push(uint16_t value) {
    /*
    Push value to the stack and increment stack pointer
    */

    operator[](SP) = value;
    SP += 2;
}

uint16_t Memory::pop()  {
    /*
    Decrement stack pointer and return the curent element
    */

    SP -= 2;
    return operator[](SP);
}