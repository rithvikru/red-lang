#include "../include/token.h"
#include <sstream>
#include <utility>

Token::Token(TokenType type, std::string lexeme, Literal literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {}

std::string Token::to_string() const
{
    std::string token_string;
    switch (this->type)
    {
        case LEFT_PAREN :
            token_string = "LEFT_PAREN" + this->lexeme + " " + this->literal.string_value;
            break;
        case RIGHT_PAREN:
            token_string = "RIGHT_PAREN" + this->lexeme + " " + this->literal.string_value;
            break;
        case LEFT_BRACE:
            token_string = "LEFT_BRACE" + this->lexeme + " " + this->literal.string_value;
            break;
        case RIGHT_BRACE:
            token_string = "RIGHT_BRACE" + this->lexeme + " " + this->literal.string_value;
            break;
        case COMMA:
            token_string = "COMMA" + this->lexeme + " " + this->literal.string_value;
            break;
        case DOT:
            token_string = "DOT" + this->lexeme + " " + this->literal.string_value;
            break;
        case MINUS:
            token_string = "MINUS" + this->lexeme + " " + this->literal.string_value;
            break;
        case PLUS:
            token_string = "PLUS" + this->lexeme + " " + this->literal.string_value;
            break;
        case SEMICOLON:
            token_string = "SEMICOLON" + this->lexeme + " " + this->literal.string_value;
            break;
        case SLASH:
            token_string = "SLASH" + this->lexeme + " " + this->literal.string_value;
            break;
        case STAR:
            token_string = "STAR" + this->lexeme + " " + this->literal.string_value;
            break;
        case BANG:
            token_string = "BANG" + this->lexeme + " " + this->literal.string_value;
            break;
        case BANG_EQUAL:
            token_string = "BANG_EQUAL" + this->lexeme + " " + this->literal.string_value;
            break;
        case EQUAL:
            token_string = "EQUAL" + this->lexeme + " " + this->literal.string_value;
            break;
        case EQUAL_EQUAL:
            token_string = "EQUAL_EQUAL" + this->lexeme + " " + this->literal.string_value;
            break;
        case GREATER:
            token_string = "GREATER" + this->lexeme + " " + this->literal.string_value;
            break;
        case GREATER_EQUAL:
            token_string = "GREATER_EQUAL" + this->lexeme + " " + this->literal.string_value;
            break;
        case LESS:
            token_string = "LESS" + this->lexeme + " " + this->literal.string_value;
            break;
        case LESS_EQUAL:
            token_string = "LESS_EQUAL" + this->lexeme + " " + this->literal.string_value;
            break;

        case ENDOFFILE:
            token_string = "ENDOFFILE" + this->lexeme + " " + this->literal.string_value;
            break;

        case STRING:
            token_string = "STRING" + this->lexeme + " " + this->literal.string_value;
            break;
        case NUMBER:
            token_string = "NUMBER";
            token_string += " " + this->lexeme;
            token_string += " " + std::to_string(this->literal.number_value);
            break;
        case IDENTIFIER:
            token_string = "IDENTIFIER";
            token_string += " " + this->lexeme + " " + this->literal.string_value;
            break;
        default:
            break;
    }

    return token_string;
}