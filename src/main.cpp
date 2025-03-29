#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string read_file_contents(const std::string& filename);

int main(int argc, char *argv[]) {
    // Disable output buffering
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    if (argc < 3) {
        std::cerr << "Usage: ./your_program tokenize <filename>" << std::endl;
        return 1;
    }

    const std::string command = argv[1];

    if (command == "tokenize") {
        std::string file_contents = read_file_contents(argv[2]);

        int code = 0;
        
        if (!file_contents.empty()) {

            for (int i = 0; i < file_contents.length(); i++) {
                char token = file_contents[i];
                switch (token) {
                    case '(': std::cout << "LEFT_PAREN ( null" << std::endl; break;
                    case ')': std::cout << "RIGHT_PAREN ) null" << std::endl; break;
                    case '{': std::cout << "LEFT_BRACE { null" << std::endl; break;
                    case '}': std::cout << "RIGHT_BRACE } null" << std::endl; break;
                    case '+': std::cout << "PLUS + null" << std::endl; break;
                    case '-': std::cout << "MINUS - null" << std::endl; break;
                    case '*': std::cout << "STAR * null" << std::endl; break;
                    case '/': std::cout << "SLASH / null" << std::endl; break;
                    case '=':
                        if (file_contents[i + 1] == '=') {
                            std::cout << "EQUAL_EQUAL == null" << std::endl;
                            ++i;
                        } else {
                            std::cout << "EQUAL = null" << std::endl;
                        }
                        break;
                    case '.': std::cout << "DOT . null" << std::endl; break;
                    case ',': std::cout << "COMMA , null" << std::endl; break;
                    case ';': std::cout << "SEMICOLON ; null" << std::endl; break;
                    default: std::cerr << "[line 1] Error: Unexpected character: " << token << std::endl; code = 65; break;
                }
            }
        }
        std::cout << "EOF  null" << std::endl; // Placeholder, remove this line when implementing the scanner
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
