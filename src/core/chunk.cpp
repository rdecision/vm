#include "core/chunk.h"

Chunk::Chunk() = default;

void Chunk::writeChunk(const std::uint8_t byte, std::uint64_t line) {
    code.push_back(byte);
    lines.push_back(line);
}

std::uint8_t Chunk::readChunk(size_t index) const {
    return code.at(index);
}

Value Chunk::readConstant(size_t index) const {
    return values.at(index);
}

size_t Chunk::getChunkSize() const {
    return code.size();
}

size_t Chunk::addConstant(const Value value) {
    values.push_back(value);
    return values.size() - 1;
}

std::uint64_t Chunk::getLine(size_t index) const {
    return lines.at(index);
}


