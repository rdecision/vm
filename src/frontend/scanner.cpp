#include "frontend/scanner.h"

Scanner::Scanner(const std::string_view source) : source(source) {
}

Token Scanner::scanToken() {
    start = current;
}
