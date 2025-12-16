#include "core/chunk.h"
#include "core/virtualmachine.h"
#include "debugger/debugger.h"
#include <iostream>



int main(int argc, const char* argv[]) {
    Chunk chunk;
    auto vm = virtualmachine(chunk);
    if (argc == 1) {
        vm.repl();
    } else if (argc == 2) {
        vm.runFile(argv[1]);
    } else {
        std::cerr << "Usage: clox [path]\n";
    }
    return 0;
}