#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <cstdint>


enum OperandType {
    NUMERIC,
    REGISTER,
};

struct Operand{
    OperandType type;
    uint16_t parsed;
};

enum Opcode {
    SETv, ADDv, SUBv, // Operation from given value
    SETr, ADDr, SUBr, // Operation from register value
    PRINT,
    IFNZ, // Skip line if register is null
    STORE, LOAD, // Heap memory function
    PUSH, POP, // Stack memory function
    ERROR // Unvalid argument
};

Opcode parse_opcode(const std::string& instr);

Operand parse_operand(const std::string& operand_str, const int pos_space_before_operand);

Operand parse_first_operand(const std::string& instr);
Operand parse_second_operand(const std::string& instr);

bool is_register(const std::string& operand);


struct Instruction {
    const Opcode opcode;
    const Operand* operands[2];

    Instruction(const std::string& raw): opcode(parse_opcode(raw)) {
        operands[0] = new Operand(parse_first_operand(raw));
        operands[1] = new Operand(parse_second_operand(raw));
    };

    inline~Instruction(){
        delete operands[0];
        delete operands[1];
    };
};


#endif