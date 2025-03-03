#include <iostream>
#include <fstream>
#include <string>

uint16_t saturated(int new_value) {
    /* Return the saturated of an int when it's going outside the range of an unsigned 16 bits int. */
    if (new_value <= std::numeric_limits<uint16_t>::min()) {
        return std::numeric_limits<uint16_t>::min();
    } else if (new_value >= std::numeric_limits<uint16_t>::max()) {
        return std::numeric_limits<uint16_t>::max();
    } else {
        return new_value;
    }
}

std::string parse_opcode(const std::string& instr) {
    /* Return the opcode (Instruction) of an code line. */
    return instr.substr(0, instr.find(' '));
}

uint16_t parse_operand(const std::string& instr) {
    /* Return the operand (Value n) of an code line. */
    return saturated(stoi(instr.substr(instr.find(' '))));
}

void exec(const std::string& program_path){
    /*
    Set the single register to 0 
    Execute in the fly the given with the instructions from the doc.
    */
    uint16_t single_register = 0;
    std::string instruction, opcode;

    std::ifstream instructions_file (program_path);
    while (getline(instructions_file, instruction)) {
        opcode = parse_opcode(instruction);
        if (opcode == "SET") {
            single_register = parse_operand(instruction);
        } else if (opcode == "ADD") {
            single_register = saturated(single_register + parse_operand(instruction));
        } else if (opcode == "SUB") {
            single_register = saturated(single_register - parse_operand(instruction));
        } else if (opcode == "PRINT") {
            std::cout << single_register << std::endl;
        } else if (opcode == "IFNZ" and single_register == 0){
            getline (instructions_file, instruction);
        }
        // No error handling so no last condition
    }
}

int main(int argc, char* argv[]) {
    /* 
    Put the first argument introduce at the execution
    into the exec function if one is given
    or show an error.
    */
    if (argc == 2) {
        exec(argv[1]);
        return 0;
    } else {
        std::cout << "Wrong file format" << std::endl;
        return 1;
    }

    return 0;
}