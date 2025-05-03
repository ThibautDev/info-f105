#include "Memory.hpp"
#include <cstdint>


uint16_tMemoryReference Memory::operator[](uint8_t address){
    return uint16_tMemoryReference(MEM, address);
}

void Memory::push(uint16_t value) {
    uint8_t lower8 = value & 0xff;
    uint8_t upper8 = value >> 8;

    MEM[SP] = lower8;
    MEM[SP + 1] = upper8;

    SP += 2;
}

uint16_t Memory::pop()  {
    SP -= 2;
    uint16_t lower8 =  MEM[SP];
    uint16_t upper8 =  MEM[SP + 1] << 8;

    return lower8 + upper8;
}