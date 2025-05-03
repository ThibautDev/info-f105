#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>

class uint16_tMemoryReference {
    private:
        uint8_t* lower8;
        uint8_t* upper8;

    public:
        uint16_tMemoryReference(uint8_t* MEM, uint8_t address) {
            this->lower8 = &MEM[address];
            this->upper8 = &MEM[address + 1];
        };

        uint16_tMemoryReference& operator=(uint16_t value) {
            *lower8 = value & 0xff;
            *upper8 = value >> 8;
            return *this;
        };

        operator uint16_t() const {
            return *lower8 + (*upper8 << 8);
        }
};

class Memory {
    private:
        uint8_t* MEM;
        uint8_t SP = 0;

    public:
        inline Memory(uint8_t nbits){
            MEM = new uint8_t[nbits];
        };

        inline ~Memory(){
            delete[] MEM;
        };

        uint16_tMemoryReference operator[](uint8_t address);

        uint16_t pop();
        void push(uint16_t value);
};

#endif