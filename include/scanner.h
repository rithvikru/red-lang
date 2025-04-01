#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <memory>

#include "token.h"

enum class ErrorType {
    NONE,
    UNTERMINATED_STRING,
    UNEXPECTED_CHARACTER
};

class Scanner {
    public:
        explicit Scanner(const std::string& source);
        std::vector<std::shared_ptr<Token>> scan_tokens();
        bool had_error() const { return error_type != ErrorType::NONE; }
        ErrorType get_error_type() const { return error_type; }
    private:
        const std::string& source;
        int start, end, current, line;
        ErrorType error_type;

        std::vector<std::shared_ptr<Token>> tokens;
        std::map<std::string, TokenType> keywords;

        bool is_end() const;
        static bool is_alpha(char c);
        static bool is_digit(char c);
        static bool is_aldigit(char c);
        void scan_token();
        char advance();
        char peek();
        char peek_next();
        bool match(char expected);
        void handle_string();
        void handle_number();
        void handle_identifier();
};