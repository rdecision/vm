#ifndef VM_INTERPRETER_H
#define VM_INTERPRETER_H
#include <string_view>
#include <frontend/file_io.h>
#include <frontend/compiler.h>
#include <core/virtualmachine.h>
#include <core/chunk.h>

enum class InterpretResult {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
};

class Interpreter {
private:
    virtualmachine vm;
public:
    [[nodiscard]] InterpretResult interpret(std::string_view source);
    [[nodiscard]] InterpretResult run();
    void repl();
};


#endif //VM_INTERPRETER_H