#ifndef clox_chunk_h
#define clox_chunk_h

#include <vector>
#include "core/value.h"
#include <cstdint>

using std::vector;

enum OpCode {
    OP_CONSTANT,
    OP_RETURN,
};

class Chunk {
    vector<std::uint8_t> code;
    vector<Value> values;
    vector<std::uint64_t> lines; // need to change to run length encoding

public:
    Chunk();
    void writeChunk(std::uint8_t byte, std::uint64_t line);
    [[nodiscard]] Value readConstant(size_t index) const;
    [[nodiscard]] std::uint8_t readChunk(size_t index) const;
    [[nodiscard]] size_t getChunkSize() const;
    [[nodiscard]] std::uint64_t getLine(size_t index) const;
    size_t addConstant(Value value);
};


#endif