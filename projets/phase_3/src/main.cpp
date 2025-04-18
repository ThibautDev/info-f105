#include <iostream>
#include <fstream>

#include "Register.hpp"
#include "Instruction.hpp"


void exec(const std::string& program_path) {
    Register a_register, b_register, c_register, d_register;
    Register* registers[4] = {&a_register, &b_register, &c_register, &d_register};


    std::string instruction;
    Opcode current_opcode;
    std::ifstream instructions_file (program_path);
    int current_line = 0;

    while (getline(instructions_file, instruction)) {
        current_line++;
        

        // switch (expression) {
        // case constant expression:
        // }

    }

}

int main(int argc, char* argv[]) {
    // Checks if file parameters are correctly formatted and executes the given file
    
    if (argc == 2) {
        exec(argv[1]);
        return 0;
    } else {
        throw std::invalid_argument("Wrong parameter format, too much argument: " + std::to_string(--argc) + ", expected: 1");
    }

    return 0;
}