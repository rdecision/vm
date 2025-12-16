#include "interpreter/interpreter.h"

#include <iostream>

void Interpreter::repl() {
    std::string line;
    while (true) {
        std::cout << ">" << std::flush;

        if (!std::getline(std::cin, line)) {
            std::cout << '\n';
            break;
        }

        interpret(line);
    }

}
InterpretResult Interpreter::interpret(std::string_view source) {
    Chunk chunk;

    if ()
}