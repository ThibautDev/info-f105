#include "Memory.hpp"


uint16_tMemoryReference& uint16_tMemoryReference::operator=(uint16_t value) {
    *lower8 = value & 0xff;
    *upper8 = value >> 8;
    return *this;
};

uint16_tMemoryReference::operator uint16_t() const {
    return *lower8 + (*upper8 << 8);
}


uint16_tMemoryReference Memory::operator[](uint8_t address){
    return uint16_tMemoryReference(MEM, address);
}

void Memory::push(uint16_t value) {
    (*this)[SP] = value;
    SP += 2;
}

uint16_t Memory::pop()  {
    SP -= 2;
    return (*this)[SP];
}