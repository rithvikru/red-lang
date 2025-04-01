#include "../include/token.h"
#include <sstream>
#include <utility>

Token::Token(TokenType type, std::string lexeme, Literal literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {}

std::string Token::to_string() const
{
    std::string token_string = this->lexeme + " null";
    switch (this->type)
    {
        case LEFT_PAREN :
            token_string = "LEFT_PAREN " + token_string;
            break;
        case RIGHT_PAREN:
            token_string = "RIGHT_PAREN " + token_string;
            break;
        case LEFT_BRACE:
            token_string = "LEFT_BRACE " + token_string;
            break;
        case RIGHT_BRACE:
            token_string = "RIGHT_BRACE " + token_string;
            break;
        case COMMA:
            token_string = "COMMA " + token_string;
            break;
        case DOT:
            token_string = "DOT " + token_string;
            break;
        case MINUS:
            token_string = "MINUS " + token_string;
            break;
        case PLUS:
            token_string = "PLUS " + token_string;
            break;
        case SEMICOLON:
            token_string = "SEMICOLON " + token_string;
            break;
        case SLASH:
            token_string = "SLASH " + token_string;
            break;
        case STAR:
            token_string = "STAR " + token_string;
            break;
        case BANG:
            token_string = "BANG " + token_string;
            break;
        case BANG_EQUAL:
            token_string = "BANG_EQUAL " + token_string;
            break;
        case EQUAL:
            token_string = "EQUAL " + token_string;
            break;
        case EQUAL_EQUAL:
            token_string = "EQUAL_EQUAL " + token_string;
            break;
        case GREATER:
            token_string = "GREATER " + token_string;
            break;
        case GREATER_EQUAL:
            token_string = "GREATER_EQUAL " + token_string;
            break;
        case LESS:
            token_string = "LESS " + token_string;
            break;
        case LESS_EQUAL:
            token_string = "LESS_EQUAL " + token_string;
            break;

        case ENDOFFILE:
            token_string = "EOF " + token_string;
            break;

        case STRING:
            token_string = "STRING " + this->lexeme;
            token_string += " " + this->literal.string_value;
            break;
        case NUMBER:
            token_string = "NUMBER " + this->lexeme;
            token_string += " " + std::to_string(this->literal.number_value);
            break;
        case IDENTIFIER:
            token_string = "IDENTIFIER " + token_string;
            break;
        default:
            break;
    }

    return token_string;
}