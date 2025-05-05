#include "Register.hpp"
#include "Instruction.hpp"
#include "Memory.hpp"

#include <fstream>
#include <iostream>


void exec(const std::string& program_path){
    Register* registers = new REGISTER_HPP::Register[4]; // Allocate 4 registers
    Memory mem(255); // Allocate a memory of 256 cells

    std::string instruction_str; 
    std::ifstream instructions_file (program_path); 

    while (getline(instructions_file, instruction_str)) {
        Instruction current_instruction(instruction_str);
        
        switch (current_instruction.opcode) {
            case SETv:
                // Set register from a value
                registers[current_instruction.operands[0] -> parsed] = current_instruction.operands[1] -> parsed; 
                break;

            case ADDv:
                // Add value to a register
                registers[current_instruction.operands[0] -> parsed] += current_instruction.operands[1] -> parsed; 
                break;

            case SUBv:
                // Sub value to a register
                registers[current_instruction.operands[0] -> parsed] -= current_instruction.operands[1] -> parsed; 
                break;

            case SETr:
                // Set register from a register value
                registers[current_instruction.operands[0] -> parsed] = registers[current_instruction.operands[1] -> parsed]; 
                break;

            case ADDr:
                // Add register value to a register
                registers[current_instruction.operands[0] -> parsed] += registers[current_instruction.operands[1] -> parsed];
                break;

            case SUBr:
                // Sub register value to a register
                registers[current_instruction.operands[0] -> parsed] -= registers[current_instruction.operands[1] -> parsed];
                break;

            case PRINT:
                std::cout << registers[current_instruction.operands[0] -> parsed] << std::endl;
                break;

            case IFNZ:
                if (registers[current_instruction.operands[0] -> parsed] == 0) {
                    getline(instructions_file, instruction_str); // Skip next line
                }
                break;

            case STORE:
                // Store register value to a given memory adresse
                mem[current_instruction.operands[0] -> parsed] = registers[current_instruction.operands[1] -> parsed];
                break;

            case LOAD:
                // Load to register the value from the given memory adresse
                registers[current_instruction.operands[1] -> parsed] = mem[current_instruction.operands[0] -> parsed];
                break;

            case PUSH:
                // Push register value to the stack
                mem.push(registers[current_instruction.operands[0] -> parsed]);
                break;

            case POP:
                // Pop to register value from the stack
                registers[current_instruction.operands[0] -> parsed] = mem.pop();
                break;
                
            case ERROR:
                // No error gestion asked
                // Just ignore this case
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