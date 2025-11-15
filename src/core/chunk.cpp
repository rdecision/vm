#include "../../include/core/chunk.h"

Chunk::Chunk() {

}

void Chunk::writeChunk(OpCode byte) {
    code.push_back(byte);
}



