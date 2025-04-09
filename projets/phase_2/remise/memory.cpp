#include "memory.hpp"


// Allocates the stack and stack pointer
uint8_t stack[256] = {0};
int stack_pointer = 0;

uint16_t read(uint8_t address){
    // Reads a 16-bit int from the stack

    uint16_t lower8 =  stack[address];
    uint16_t upper8 =  stack[address + 1] << 8;

    return lower8 + upper8;
}

void write(uint8_t address, uint16_t value) {
    // Writes a 16-bit int to the stack

    uint8_t lower8 = value & 0xff;
    uint8_t upper8 = value >> 8;

    stack[address] = lower8;
    stack[address + 1] = upper8;
}

void push(uint16_t value) {
    // Writes a 16-bit int to the stack
    // And moves the stack pointer above this int 

    write(stack_pointer, value);
    stack_pointer += 2;
}

uint16_t pop() {
    // Reads a 16-bit int from the stack
    // And moves the stack pointer below this int 

    stack_pointer -= 2;
    return read(stack_pointer);
}