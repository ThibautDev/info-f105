#include "Instruction.hpp"
#include "saturated.hpp"


Opcode parse_opcode(const std::string& instr) {
    /*
    Return the corresponding enum Opcode from an instruction string
    */
    
    std::string opcode_str = instr.substr(0, instr.find(' ')); // Get the opcode substring
 
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
    /*
    Build Operand by checking if the opperand is a register or a value
    */

    if (is_register(operand_str)) {
        type = REGISTER;
        parsed = operand_str[0] - 'a';
    } else {
        type = NUMERIC;
        parsed = saturated(stoi(operand_str));
    }
}

Operand* parse_first_operand(const std::string& instr) {
    /*
    Get the substring of the first operand from an instruction line and allocate it in memory if the operand exist
    */

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
    /*
    Get the substring of the second operand from an instruction line and allocate it in memory if the operand exist
    */

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
    /*
    Check if the given operand is a value or a register
    */

    char register_name = operand[0];
    return ('a' <= register_name and register_name <= 'd' and operand.length() == 1);
}

Instruction::Instruction(const std::string& raw)
: opcode(parse_opcode(raw)) 
{
    operands[0] = parse_first_operand(raw);
    operands[1] = parse_second_operand(raw);
};