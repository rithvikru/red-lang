#ifndef LOX_TOKEN_H
#define LOX_TOKEN_H

#include <string>

enum TokenType {
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,
    
    // One or two character tokens
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    
    // Literals
    IDENTIFIER,
    STRING,
    NUMBER,

    ENDOFFILE
};

struct Literal {
    std::string string_value;
    double number_value;
};

class Token {
    public:
        TokenType type;
        std::string lexeme;
        Literal literal;
        int line;

        Token(TokenType type, std::string lexeme, Literal literal, int line);
        Token(const Token& t) = default;
        std::string to_string() const;
};

#endif //LOX_TOKEN_H