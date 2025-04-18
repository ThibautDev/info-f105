#include "Instruction.hpp"

// struct Instruction {
//     const Opcode opcode;
//     const Operand* operands[2];
//     Instruction(const std::string& raw);
//     inline ~Instruction();
// };



Opcode parse_opcode(const std::string& instr) {
    std::string opcode_str = instr.substr(0, instr.find(' '));
 
    if (opcode_str == "SETv") {
        return SETv;
    } else if (opcode_str == "ADDv") {
        return ADDv;
    } else if (opcode_str == "SUBv") {
        return SUBv;
    } else if (opcode_str == "SETr") {
        return SETr;
    } else if (opcode_str == "ADDr") {
        return ADDr;
    } else if (opcode_str == "SUBr") {
        return SUBr;
    } else if (opcode_str == "IFNZ") {
        return IFNZ;
    } else if (opcode_str == "STORE") {
        return STORE;
    } else if (opcode_str == "LOAD") {
        return LOAD;
    } else if (opcode_str == "PUSH") {
        return PUSH;
    } else if (opcode_str == "POP") {
        return POP;
    } else {
        throw std::invalid_argument("Unknown opcode: " + opcode_str);
    }
}

Operand parse_operand(const std::string& operand_str){
    Operand operand; 

    if (is_register(operand_str)) {
        operand.type = REGISTER;
        operand.parsed = operand_str[0] - 'a';
    } else {
        operand.type = NUMERIC;
        operand.parsed = saturated(stoi(operand_str));
    }

    return operand;
}

Operand* parse_operands(const std::string& instr) {
    Operand* operands = new Operand[2];

    int first_space_pos = instr.find(' ');
    int second_space_pos = instr.find(' ', first_space_pos + 1);
    int third_space_pos = instr.find(' ', second_space_pos + 1);

    operands[0] = parse_operand(
        instr.substr(first_space_pos + 1, second_space_pos - first_space_pos - 1)
    );

    operands[1] = parse_operand(
        instr.substr(second_space_pos + 1, third_space_pos - second_space_pos - 1)
    );

    return operands;
}

bool is_register(const std::string& operand) {
    char register_name = operand[0];
    return ('a' <= register_name and register_name <= 'd' and operand.length() == 1);
}

Instruction::Instruction(const std::string& raw): 
    opcode(parse_opcode(raw)),
    operands(parse_operands(raw))
{}