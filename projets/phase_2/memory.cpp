#include "memory.hpp"


uint8_t stack[256] = {0};
int stack_pointer = 0;

uint16_t read(uint8_t address){
    return stack[address] + (stack[address + 1] << 8);
}

void write(uint8_t address, uint16_t value) {
    uint8_t lower8 = value & 0xff;
    uint8_t upper8 = value >> 8;

    stack[address] = lower8;
    stack[address + 1] = upper8;
}

void push(uint16_t value) {
    write(stack_pointer, value);
    stack_pointer += 2;
}

uint16_t pop() {
    stack_pointer -= 2;
    uint16_t val = read(stack_pointer);
    return val;
}