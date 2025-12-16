#ifndef VM_COMPILER_H
#define VM_COMPILER_H

#include <string_view>
#include <frontend/scanner.h>
#include <core/chunk.h>

class Compiler {
private:
    Scanner scanner;
public:
    bool compile(std::string_view source, Chunk& chunk);
    Compiler();

};


#endif //VM_COMPILER_H