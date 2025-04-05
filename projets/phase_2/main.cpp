#include "main.hpp"


uint16_t saturated(int new_value) {
    if (new_value < 0) {
        return 0;
    } else if (new_value > UINT16_MAX) {
        return UINT16_MAX;
    } else {
        return new_value;
    }
}

std::string parse_opcode(const std::string& instr) {
    return instr.substr(0, instr.find(' '));
}

std::string parse_first_operand(const std::string& instr) {
    int first_space_pos = instr.find(' ');
    int second_space_pos = instr.find(' ', first_space_pos + 1);

    return instr.substr(first_space_pos + 1, second_space_pos - first_space_pos - 1);
}

std::string parse_second_operand(const std::string& instr) {
    int first_space_pos = instr.find(' ');
    int second_space_pos = instr.find(' ', first_space_pos + 1);
    int third_space_pos = instr.find(' ', second_space_pos + 1);

    return instr.substr(second_space_pos + 1, third_space_pos - second_space_pos - 1);
}

bool is_register(const std::string& operand) {
    char register_name = operand[0];
    return ('a' <= register_name and register_name <= 'd' and operand.length() == 1);
}

uint16_t* get_register(const std::string& instruction, uint16_t **registers, int current_line) {
    std::string operand = parse_first_operand(instruction);

    if (is_register(operand)) {
        return registers[operand[0] - 'a'];
    } else {
        throw std::invalid_argument("Invalid register name: " + operand + " at line " + std::to_string(current_line));
    }
}

uint16_t get_value(const std::string& instruction, uint16_t** registers) {
    std::string operand = parse_second_operand(instruction);
    // std::cout << 'hello';

    if (is_register(operand)) {
        return *registers[operand[0] - 'a'];
    } else {
        return saturated(stoi(operand));
    }
}

void exec(const std::string& program_path){
    uint16_t a_register = 0, b_register = 0, c_register = 0, d_register = 0;
    uint16_t* registers[4] = {&a_register, &b_register, &c_register, &d_register};

    std::string instruction, opcode, first_operand, second_operand;

    std::ifstream instructions_file (program_path);
    int current_line = 0;

    while (getline(instructions_file, instruction)) {
        current_line++;

        opcode = parse_opcode(instruction);

        if (opcode == "SET") {
            uint16_t* register_to_set = get_register(instruction, registers, current_line);
            uint16_t set_value = get_value(instruction, registers);

            *register_to_set = set_value;
        } else if (opcode == "ADD") {
            uint16_t* register_to_add = get_register(instruction, registers, current_line);
            uint16_t add_value = get_value(instruction, registers);

            *register_to_add = saturated(*register_to_add + add_value);
        } else if (opcode == "SUB") {
            uint16_t* register_to_sub = get_register(instruction, registers, current_line);
            uint16_t sub_value = get_value(instruction, registers);

            *register_to_sub = saturated(*register_to_sub - sub_value);
        } else if (opcode == "PRINT") {
            uint16_t* register_to_print = get_register(instruction, registers, current_line);
            std::cout << *register_to_print << std::endl;
        } else if (opcode == "IFNZ") {
            uint16_t* register_to_check = get_register(instruction, registers, current_line);

            if (*register_to_check == 0) {
                getline (instructions_file, instruction);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        exec(argv[1]);
        return 0;
    } else {
        throw std::invalid_argument("Wrong parameter format, too much argument: " + std::to_string(--argc) + ", expected: 1");
    }

    return 0;
}