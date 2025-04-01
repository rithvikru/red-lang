#include "../include/scanner.h"

bool Scanner::is_end() const {
    return this->current >= this->source.length();
}

bool Scanner::is_digit(char c) {
    return isdigit(c);
}

bool Scanner::is_alpha(char c) {
    return isalpha(c) || c == '_';
}

bool Scanner::is_aldigit(char c) {
    return is_alpha(c) || is_digit(c);
}

char Scanner::advance() {
    return this->source[this->current++];
}

char Scanner::peek() {
    return this->source[this->current];
}

char Scanner::peek_next() {
    return this->source[this->current + 1];
}

bool Scanner::match(char c) {
    if (is_end()) return false;
    if (this->source[this->current] != c) return false;
    this->current++;
    return true;
}

void Scanner::handle_string() {
    while (this->peek() != '"' && !this->is_end()) {
        this->current++;
    }
    if (this->is_end()) {
        std::cout << "[line " << this->line << " ] Error: Unterminated string." << std::endl;
        return;
    }

    Literal literal;
    literal.string_value = this->source.substr(this->start + 1, this->current - this->start + 1);

    this->tokens.emplace_back(new Token(STRING, std::string("\"") + literal.string_value + "\"", literal, this->line));
}

void Scanner::handle_number() {
    while (this->is_digit(this->peek())) {
        this->advance();
    }

    if (this->peek() == '.' && this->is_digit(this->peek_next())) {
        this->advance();

        while (this->is_digit(this->peek())) {
            this->advance();
        }
    }

    std::string s_num = this->source.substr(this->start, this->current - this->start);
    Literal literal;
    literal.number_value = std::stod(s_num);

    this->tokens.emplace_back(new Token(NUMBER, s_num, literal, this->line));
}

void Scanner::handle_identifier() {
    while (this->is_aldigit(this->peek())) {
        this->advance();
    }

    this->tokens.emplace_back(new Token(IDENTIFIER, this->source.substr(this->start, this->current - this->start), Literal(), this->line));
}

void Scanner::scan_token() {
    char c = this->advance();

    switch (c) {
        case '(': this->tokens.emplace_back(new Token(LEFT_PAREN, "(", Literal(), this->line)); break;
        case ')': this->tokens.emplace_back(new Token(RIGHT_PAREN, ")", Literal(), this->line)); break;
        case '{': this->tokens.emplace_back(new Token(LEFT_BRACE, "{", Literal(), this->line)); break;
        case '}': this->tokens.emplace_back(new Token(RIGHT_BRACE, "}", Literal(), this->line)); break;
        case ',': this->tokens.emplace_back(new Token(COMMA, ",", Literal(), this->line)); break;
        case '.': this->tokens.emplace_back(new Token(DOT, ".", Literal(), this->line)); break;
        case ';': this->tokens.emplace_back(new Token(SEMICOLON, ";", Literal(), this->line)); break;
        case '+': this->tokens.emplace_back(new Token(PLUS, "+", Literal(), this->line)); break;
        case '-': this->tokens.emplace_back(new Token(MINUS, "-", Literal(), this->line)); break;
        case '*': this->tokens.emplace_back(new Token(STAR, "*", Literal(), this->line)); break;
        case ' ': break;
        case '\r': break;
        case '\t': break;
        case '\n': this->line++; break;
        case '=': {
            if (match('=')) { this->tokens.emplace_back(new Token(EQUAL_EQUAL, "==", Literal(), this->line)); break; }
            else { this->tokens.emplace_back(new Token(EQUAL, "=", Literal(), this->line)); break; }
        }
        case '!': {
            if (match('=')) { this->tokens.emplace_back(new Token(BANG_EQUAL, "!=", Literal(), this->line)); break; }
            else { this->tokens.emplace_back(new Token(BANG, "!", Literal(), this->line)); break; }
        }
        case '<': {
            if (match('=')) { this->tokens.emplace_back(new Token(LESS_EQUAL, "<=", Literal(), this->line)); break; }
            else { this->tokens.emplace_back(new Token(LESS, "<", Literal(), this->line)); break; }
        }
        case '>': {
            if (match('=')) { this->tokens.emplace_back(new Token(GREATER_EQUAL, ">=", Literal(), this->line)); break; }
            else { this->tokens.emplace_back(new Token(GREATER, ">", Literal(), this->line)); break; }
        }
        case '/': {
            if (match('/')) { while (peek() != '\n' && !is_end()) this->current++; break; }
            else { this->tokens.emplace_back(new Token(SLASH, "/", Literal(), this->line)); break; }
        }
        case '"': this->handle_string(); break;
        default: {
            if (this->is_digit(c)) {
                this->handle_number();
            } else if (this->is_alpha(c)) {
                this->handle_identifier();
            } else {
                std::cerr << "[line " << this->line << "] Error: Unexpected character: " << c << std::endl;
                return;
            }
        }
    }
}

std::vector<std::shared_ptr<Token>> Scanner::scan_tokens() {
    while (!this->is_end()) {
        this->start = this->current;
        this->scan_token();
    }

    this->tokens.emplace_back(new Token(ENDOFFILE, "", Literal(), this->line));

    return std::move(this->tokens);
}

Scanner::Scanner(const std::string& source) : source(source), start(0), current(0), line(1) {
    this->end = source.length();
}