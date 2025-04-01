#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "../include/scanner.h"

std::string read_file_contents(const std::string& filename);

int main(int argc, char *argv[]) {
    // Disable output buffering
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    if (argc < 3) {
        std::cerr << "Usage: ./your_program tokenize <filename>" << std::endl;
        return 1;
    }

    int code = 0;

    const std::string command = argv[1];

    if (command == "tokenize") {
        std::string file_contents = read_file_contents(argv[2]);
        
        Scanner scanner(file_contents);
        std::vector<std::shared_ptr<Token>> tokens = scanner.scan_tokens();
        
        if (scanner.had_error()) {
            switch (scanner.get_error_type()) {
                case ErrorType::UNTERMINATED_STRING:
                    code = 65;
                    break;
                case ErrorType::UNEXPECTED_CHARACTER:
                    code = 65;
                    break;
                default:
                    code = 0;
                    break;
            }
        }
        
        for (const auto& token : tokens) {
            std::cout << token->to_string() << std::endl;
        }
        
        return code;
        
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}

std::string read_file_contents(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        std::exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
