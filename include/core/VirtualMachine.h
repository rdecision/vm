#ifndef VM_VIRTUAL_MACHINE_H
#define VM_VIRTUAL_MACHINE_H

#define DEBUG_TRACE_EXECUTION
#include <array>
#include <filesystem>
#include <string_view>

#include "chunk.h"

enum class InterpretResult {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
};

constexpr int STACK_SIZE = 1024;

class VirtualMachine {
    const Chunk& currentChunk; // can we guarantee that chunk outlives vm?
    const uint8_t* ip{}; /// TODO: check if vector indexing is faster?
    std::array<Value, STACK_SIZE> stack {}; /// TODO check if just using vector reduces binary size
    Value* stackTop{}; /// TODO check if this can be made smart
    // points past the last element

    uint8_t readByte() noexcept {return *ip++;} /// TODO check if macros are faster
    Value readConstant() noexcept {return currentChunk.readConstant(readByte());}
public:
    [[nodiscard]] InterpretResult interpret(std::string_view line);
    [[nodiscard]] InterpretResult run();
    [[nodiscard]] Value pop() noexcept {stackTop--; return *stackTop;}
    void push(Value value) noexcept {*stackTop = value; stackTop++;}
    VirtualMachine(Chunk& chunk);
    VirtualMachine(const Chunk&&) = delete;
    VirtualMachine(Chunk&&) = delete;
    void repl();



};

#endif //VM_VIRTUAL_MACHINE_H