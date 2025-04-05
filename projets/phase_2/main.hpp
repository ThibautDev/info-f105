#include <iostream>
#include <fstream>
#include <stdexcept>

#include <string>
#include <cstdint>

#include "memory.cpp"

uint16_t saturated(int new_value);

std::string parse_opcode(const std::string& instr);
std::string parse_first_operand(const std::string& instr);
std::string parse_second_operand(const std::string& instr);

bool is_register(const std::string& operand);

uint16_t* get_register(const std::string& instruction, uint16_t* registers, int current_line);
uint16_t get_value(const std::string& instruction, uint16_t* registers);

void exec(const std::string& program_path);