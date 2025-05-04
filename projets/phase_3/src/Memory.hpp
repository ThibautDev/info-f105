#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>


struct uint16_tMemoryReference {
    uint8_t* lower8;
    uint8_t* upper8;

    inline uint16_tMemoryReference(uint8_t* MEM, uint8_t address)
    : lower8( &MEM[address]), upper8( &MEM[address + 1])
    {}

    uint16_tMemoryReference& operator=(uint16_t value);

    operator uint16_t() const;
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