#ifndef VM_DEBUGGER_H
#define VM_DEBUGGER_H

#include "core/chunk.h"
#include <string_view>

namespace debugger {
    void disassembleChunk(const Chunk& chunk, std::string_view name);
    int disassembleInstruction(const Chunk& chunk, int offset);
    int simpleInstruction(std::string_view name, int offset);
    int constantInstruction(std::string_view name, const Chunk& chunk, int offset);
    void printValue(Value value);


}

#endif