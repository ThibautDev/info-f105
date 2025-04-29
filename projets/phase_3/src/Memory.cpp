#include "Memory.hpp"


uint8_t& Memory::operator[](uint16_t index)  {
    return MEM[index];
};

uint16_t Memory::pop(){
    return MEM[--SP];
};

void Memory::push(uint16_t value){
    MEM[++SP] = value;
};