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
        case NUMBER: {
            double value = this->literal.number_value;
            std::string number_str;
            
            if (value == static_cast<int>(value)) {
                number_str = std::to_string(static_cast<int>(value)) + ".0";
            } else {
                number_str = this->lexeme;
            }
            
            token_string = "NUMBER " + this->lexeme + " " + number_str;
            break;
        }
        case IDENTIFIER:
            token_string = "IDENTIFIER " + token_string;
            break;

        case AND:
            token_string = "AND " + token_string;
            break;
        case CLASS:
            token_string = "CLASS " + token_string;
            break;
        case IF:
            token_string = "IF " + token_string;
            break;
        case ELSE:
            token_string = "ELSE " + token_string;
            break;
        case TRUE:
            token_string = "TRUE " + token_string;
            break;
        case FALSE:
            token_string = "FALSE " + token_string;
            break;
        case FOR:
            token_string = "FOR " + token_string;
            break;
        case FUN:
            token_string = "FUN " + token_string;
            break;
        case NIL:
            token_string = "NIL " + token_string;
            break;
        case OR:
            token_string = "OR " + token_string;
            break;
        case PRINT:
            token_string = "PRINT " + token_string;
            break;
        case RETURN:
            token_string = "RETURN " + token_string;
            break;
        case SUPER:
            token_string = "SUPER " + token_string;
            break;
        case THIS:
            token_string = "THIS " + token_string;
            break;
        case VAR:
            token_string = "VAR " + token_string;
            break;
        case WHILE:
            token_string = "WHILE " + token_string;
            break;

        default:
            break;
    }
    return token_string;    
}