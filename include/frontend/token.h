#ifndef VM_TOKEN_H
#define VM_TOKEN_H

#include <cstddef>
#include <optional>
#include <string>

enum class TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS,
    SEMICOLON, SLASH, STAR,
    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    // Literals.
    IDENTIFIER, STRING, NUMBER,
    // Keywords.
    AND, CLASS, ELSE, FALSE,
    FOR, FUN, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS,
    TRUE, VAR, WHILE,

    ERROR, END_OF_FILE
  };

struct Token {
    TokenType type;
    size_t start;
    size_t length;
    size_t line;
    std::optional<std::string> error_msg = std::nullopt;

    Token(const TokenType type, const size_t start, const size_t length, const size_t line) :
    type(type), start(start), length(length), line(line) {}

    errorToken(const size_t line, const std::string& error_msg) {
        return Token(TokenType::ERROR, )
    }
};


#endif //VM_TOKEN_H