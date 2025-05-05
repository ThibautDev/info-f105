#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <cstdint>


enum Opcode {
    SETv, ADDv, SUBv, // Operation from given value
    SETr, ADDr, SUBr, // Operation from register value
    PRINT,
    IFNZ, // Skip line if register is null
    STORE, LOAD, // Heap memory function
    PUSH, POP, // Stack memory function
    ERROR // Unvalid argument
};

enum OperandType {
    NUMERIC,
    REGISTER,
};

struct Operand{
    OperandType type;
    uint16_t parsed;

    Operand(const std::string& raw);
};

Opcode parse_opcode(const std::string& instr);

Operand *parse_first_operand(const std::string& instr);
Operand *parse_second_operand(const std::string& instr);

bool is_register(const std::string& operand);

struct Instruction {
    const Opcode opcode;
    const Operand* operands[2];

    Instruction(const std::string& raw);

    inline~Instruction(){
        delete operands[0];
        delete operands[1];
    };
};


#endif
