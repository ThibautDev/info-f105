#include "Register.hpp"
#include "Instruction.hpp"
#include <fstream>
#include <iostream>


void exec(const std::string& program_path){
    REGISTER_HPP::Register* registers = new REGISTER_HPP::Register[4];

    std::string instruction_str;
    std::ifstream instructions_file (program_path);

    while (getline(instructions_file, instruction_str)) {
        INSTRUCTION_HPP::Instruction current_instruction(instruction_str);
        std::cout << current_instruction.operands[0];
    }
}

int main(int argc, char* argv[]) {
    exec(argv[1]);
    return 0;
}