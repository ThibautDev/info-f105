#include "Instruction.hpp"
#include "saturated.hpp"


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
    } else if (opcode_str == "PRINT") {
        return PRINT;
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
        return ERROR;
    }
}

Operand::Operand(const std::string& operand_str) {
    if (is_register(operand_str)) {
        type = REGISTER;
        parsed = operand_str[0] - 'a';
    } else {
        type = NUMERIC;
        parsed = saturated(stoi(operand_str));
    }
}

Operand* parse_first_operand(const std::string& instr) {
    int first_space_pos = instr.find(' ');
    int second_space_pos = instr.find(' ', first_space_pos + 1);

    if (first_space_pos > 0) {
        std::string first_operand_str = instr.substr(first_space_pos + 1, second_space_pos - first_space_pos - 1);
        return new Operand(first_operand_str);
    } else {
        return nullptr;
    }
}

Operand* parse_second_operand(const std::string& instr) {    
    int first_space_pos = instr.find(' ');
    int second_space_pos = instr.find(' ', first_space_pos + 1);
    int third_space_pos = instr.find(' ', second_space_pos + 1);

    if (second_space_pos > 0) {
        std::string second_operand_str = instr.substr(second_space_pos + 1, third_space_pos - second_space_pos - 1);
        return new Operand(second_operand_str);
    } else {
        return nullptr;
    }

}


bool is_register(const std::string& operand) {
    char register_name = operand[0];
    return ('a' <= register_name and register_name <= 'd' and operand.length() == 1);
}