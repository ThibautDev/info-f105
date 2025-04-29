#include "Register.hpp"
#include "Instruction.hpp"
#include "Memory.hpp"

#include <fstream>
#include <iostream>


void exec(const std::string& program_path){
    Register* registers = new REGISTER_HPP::Register[4];

    std::string instruction_str;
    std::ifstream instructions_file (program_path);

    while (getline(instructions_file, instruction_str)) {
        Instruction current_instruction(instruction_str);
        Memory mem(255);


        switch (current_instruction.opcode) {
            case SETv:
                registers[current_instruction.operands[0] -> parsed] = current_instruction.operands[1] -> parsed;
                break;

            case ADDv:
                registers[current_instruction.operands[0] -> parsed] += current_instruction.operands[1] -> parsed;
                break;

            case SUBv:
                registers[current_instruction.operands[0] -> parsed] -= current_instruction.operands[1] -> parsed;
                break;

            case SETr:
                registers[current_instruction.operands[0] -> parsed] = registers[current_instruction.operands[1] -> parsed];
                break;

            case ADDr:
                registers[current_instruction.operands[0] -> parsed] += registers[current_instruction.operands[1] -> parsed];
                break;

            case SUBr:
                registers[current_instruction.operands[0] -> parsed] -= registers[current_instruction.operands[1] -> parsed];
                break;

            case PRINT:
                std::cout << registers[current_instruction.operands[0] -> parsed] << std::endl;
                break;

            case IFNZ:
                if (registers[current_instruction.operands[0] -> parsed] == 0) {
                    getline(instructions_file, instruction_str);
                }
                break;

            case STORE:
                mem[current_instruction.operands[0] -> parsed] = current_instruction.operands[1] -> parsed;
                break;

            case LOAD:
                registers[current_instruction.operands[1] -> parsed] = mem[current_instruction.operands[0] -> parsed];
                break;

            case PUSH:
                mem.push(registers[current_instruction.operands[0] -> parsed]);
                break;

            case POP:
                registers[current_instruction.operands[0] -> parsed] = mem.pop();
                break;
                
            case ERROR:
              break;
            }

        std::cout << current_instruction.opcode << std::endl;
        std::cout << current_instruction.operands[0] -> parsed << std::endl;
        std::cout << current_instruction.operands[1] -> parsed << std::endl;
    }
}

int main(int argc, char* argv[]) {
    exec(argv[1]);
    return 0;
}