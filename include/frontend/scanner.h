#ifndef VM_SCANNER_H
#define VM_SCANNER_H

#include <string_view>
#include "token.h"

class Scanner {
    size_t start = 0;
    size_t end = 0;
    size_t line = 1;
    size_t current = 0;
    const std::string_view source;

    bool isAtEnd() const {return current == source.size() - 1;}
    char advance();
    Token scanToken();
public:
    Scanner(std::string_view source);
    void scan();

};


#endif //VM_SCANNER_H