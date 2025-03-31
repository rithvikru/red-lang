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
        int line = 1;
        
        if (!file_contents.empty()) {
            for (int i = 0; i < file_contents.length(); ++i) {
                char token = file_contents[i];
                std::string token_type, lexeme, literal = "null";
                switch (token) {
                    case '(': token_type = "LEFT_PAREN"; lexeme = "("; break;
                    case ')': token_type = "RIGHT_PAREN"; lexeme = ")"; break;
                    case '{': token_type = "LEFT_BRACE"; lexeme = "{"; break;
                    case '}': token_type = "RIGHT_BRACE"; lexeme = "}"; break;
                    case '+': token_type = "PLUS"; lexeme = "+"; break;
                    case '-': token_type = "MINUS"; lexeme = "-"; break;
                    case '*': token_type = "STAR"; lexeme = "*"; break;
                    case '"': {
                        token_type = "STRING"; lexeme = "\""; literal = "";
                        while (i < file_contents.length()) {
                            ++i;
                            if (file_contents[i] == '"') {
                                lexeme += "\"";
                                break;
                            }
                            literal += file_contents[i];
                            lexeme += file_contents[i];
                        }
                        if (i == file_contents.length()) {
                            std::cerr << "[line " << line << "] Error: Unterminated string." << std::endl;
                            code = 65;
                            continue;
                        }
                        break;
                    }
                    case ' ': case '\t': break;
                    case '\n': ++line; break;
                    case '/': {
                        if (file_contents[i + 1] == '/') {
                            while (i < file_contents.length() && file_contents[i] != '\n') {
                                ++i;
                            }
                            ++line;
                        } else {
                            token_type = "SLASH"; lexeme = "/";
                        }
                        break;
                    }
                    case '=': {
                        if (file_contents[i + 1] == '=') {
                            token_type = "EQUAL_EQUAL"; lexeme = "==";
                            ++i;
                        } else {
                            token_type = "EQUAL"; lexeme = "=";
                        }
                        break;
                    }
                    case '!': {
                        if (file_contents[i + 1] == '=') {
                            token_type = "BANG_EQUAL"; lexeme = "!=";
                            ++i;
                        } else {
                            token_type = "BANG"; lexeme = "!";
                        }
                        break;
                    }
                    case '<': {
                        if (file_contents[i + 1] == '=') {
                            token_type = "LESS_EQUAL"; lexeme = "<=";
                            ++i;
                        } else {
                            token_type = "LESS"; lexeme = "<";
                        }
                        break;
                    }
                    case '>': {
                        if (file_contents[i + 1] == '=') {
                            token_type = "GREATER_EQUAL"; lexeme = ">=";
                            ++i;
                        } else {
                            token_type = "GREATER"; lexeme = ">";
                        }
                        break;
                    }
                    case '.': token_type = "DOT"; lexeme = "."; break;
                    case ',': token_type = "COMMA"; lexeme = ","; break;
                    case ';': token_type = "SEMICOLON"; lexeme = ";"; break;
                    default: {
                        if (isdigit(token)) {
                            token_type = "NUMBER", lexeme = token;
                            ++i;
                            while (i < file_contents.length() && (isdigit(file_contents[i]) || file_contents[i] == '.')) {
                                lexeme += file_contents[i];
                                ++i;
                            }
                            --i;
                            double num = std::stod(lexeme);
                            literal = (int(num) == num) ? std::to_string((int)num) + ".0" : lexeme;
                        } else if (isalpha(token) || token == '_') {
                            token_type = "IDENTIFIER", lexeme = token;
                            ++i;
                            while (i < file_contents.length() && (isalpha(file_contents[i]) || file_contents[i] == '_')) {
                                lexeme += file_contents[i];
                                ++i;
                            }
                            --i;
                        } else {
                            std::cerr << "[line " << line << "] Error: Unexpected character: " << token << std::endl;
                            code = 65;
                        }
                        break;
                    }
                }
                if (lexeme != "") {
                    std::cout << token_type << " " << lexeme << " " << literal << std::endl;
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
