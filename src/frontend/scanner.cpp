#include "frontend/scanner.h"

Scanner::Scanner(const std::string_view source) : source(source) {
}

Token Scanner::scanToken() {
    start = current;
    if (isAtEnd()) return Token(TokenType::END_OF_FILE, start, current - start, line);
    return Token()

}
