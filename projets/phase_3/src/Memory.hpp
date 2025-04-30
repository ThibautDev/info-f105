#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>


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

        uint8_t& operator[](uint16_t index);

        uint16_t pop();
        void push(uint16_t value);
};

#endif