#include "Register.hpp"
#include "Instruction.hpp"
#include "Memory.hpp"

#include <cstdint>
#include <fstream>
#include <iostream>


void exec(const std::string& program_path){
    Register* registers = new REGISTER_HPP::Register[4];
    Memory mem(255);

    std::string instruction_str;
    std::ifstream instructions_file (program_path);

    while (getline(instructions_file, instruction_str)) {
        Instruction current_instruction(instruction_str);
        
        uint16_t first_operand = current_instruction.operands[0] -> parsed;
        uint16_t second_operand = current_instruction.operands[1] -> parsed;

        switch (current_instruction.opcode) {
            case SETv:
                registers[first_operand] = second_operand;
                break;

            case ADDv:
                registers[first_operand] += second_operand;
                break;

            case SUBv:
                registers[first_operand] -= second_operand;
                break;

            case SETr:
                registers[first_operand] = registers[second_operand];
                break;

            case ADDr:
                registers[first_operand] += registers[second_operand];
                break;

            case SUBr:
                registers[first_operand] -= registers[second_operand];
                break;

            case PRINT:
                std::cout << registers[first_operand] << std::endl;
                break;

            case IFNZ:
                if (registers[first_operand] == 0) {
                    getline(instructions_file, instruction_str);
                }
                break;

            case STORE:
                mem[first_operand] = registers[second_operand];
                break;

            case LOAD:
                registers[second_operand] = mem[first_operand];
                break;

            case PUSH:
                mem.push(registers[first_operand]);
                break;

            case POP:
                registers[first_operand] = mem.pop();
                break;
                
            case ERROR:
              break;
        }
    }
}

int main(int argc, char* argv[]) {
    // Checks if file parameters are correctly formatted and executes the given file
    
    if (argc == 2) {
        exec(argv[1]);
        return 0;
    } else {
        // I'm doing error gestion here to avoid getting unused parameter ‘argc’ warning
        throw std::invalid_argument("Wrong parameter format, argument(s): " + std::to_string(--argc) + ", expected: 1");
    }

    return 0;
}