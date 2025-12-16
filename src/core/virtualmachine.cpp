#include "core/virtualmachine.h"
#include <iostream>
#include <fstream>
#ifdef DEBUG_TRACE_EXECUTION
#include "debugger/debugger.h"
#endif


virtualmachine::virtualmachine(Chunk& chunk) : currentChunk(chunk), ip(chunk.getCode()) {
    stackTop = stack.data();
}

void virtualmachine::repl() {
    std::string line;
    while (true) {
        std::cout << "> ";

        if (!std::getline(std::cin, line)) {
            if (std::cin.eof()) {break;}
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    interpret(line);
}

InterpretResult virtualmachine::interpret(std::string_view s) {
    return run();
}


/// TODO: investigate direct threaded code, jump table or computed goto
InterpretResult virtualmachine::run() {
    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        printf("          ");
        for (Value* slot = stack.data(); slot < stackTop; slot++) {
            printf("[ ");
            debugger::printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        debugger::disassembleInstruction(currentChunk, static_cast<int>(ip - currentChunk.getCode()));
#endif
        uint8_t instruction;
        switch (instruction = readByte()) {
            case OP_RETURN: {
                debugger::printValue(pop());
                printf("\n");
                return InterpretResult::INTERPRET_OK;
            }
            case OP_CONSTANT: {
                Value constant = readConstant();
                push(constant);
                break;
            }
            case OP_NEGATE: {
                push(-pop()); break;
            }
            case OP_ADD: {
                double a = pop();
                double b = pop();
                push (a + b);
                break;
            }
            case OP_SUBTRACT: {
                double a = pop();
                double b = pop();
                push (a - b);
                break;
            }
            case OP_MULTIPLY: {
                double a = pop();
                double b = pop();
                push (a * b);
                break;
            }
            case OP_DIVIDE: {
                double a = pop();
                double b = pop();
                push (a / b);
                break;
            }

        }
    }
}




