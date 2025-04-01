#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <memory>

#include "token.h"

class Scanner {
    public:
        explicit Scanner(const std::string& source);
        std::vector<std::shared_ptr<Token>> scan_tokens();
    private:
        const std::string& source;
        int start, end, current, line;

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