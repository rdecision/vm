#include "core/VirtualMachine.h"
#include <iostream>
#ifdef DEBUG_TRACE_EXECUTION
#include "debugger/debugger.h"
#endif


VirtualMachine::VirtualMachine(const Chunk& chunk) : currentChunk(chunk), ip(chunk.getCode()) {
    stackTop = stack.data();
}

InterpretResult VirtualMachine::interpret() {
    return run();
}

/// TODO: investigate direct threaded code, jump table or computed goto
InterpretResult VirtualMachine::run() {
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




