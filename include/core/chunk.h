#ifndef clox_chunk_h
#define clox_chunk_h

#include <vector>
#include "core/value.h"
#include <cstdint>
#include <utility>

using std::vector;

enum OpCode {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
};

class Chunk {
    vector<std::uint8_t> code;
    vector<Value> values;
    vector<std::uint64_t> lines;
    vector<std::pair<uint64_t, uint64_t>> lineRuns;

public:
    Chunk();
    void writeChunk(std::uint8_t byte, std::uint64_t line);
    [[nodiscard]] Value readConstant(size_t index) const;
    [[nodiscard]] std::uint8_t readChunk(size_t index) const;
    [[nodiscard]] size_t getChunkSize() const;
    [[nodiscard]] std::uint64_t getLine(size_t index) const;
    size_t addConstant(Value value);
    [[nodiscard]] const std::uint8_t* getCode() const;
};


#endif