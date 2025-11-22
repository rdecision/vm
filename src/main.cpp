#include "core/chunk.h"
#include "debugger/debugger.h"


int main() {

    Chunk chunk2;
    int constant = chunk2.addConstant(1.2);
    chunk2.writeChunk(OP_CONSTANT, 123);
    chunk2.writeChunk(constant, 123);
    chunk2.writeChunk(OP_RETURN, 123);

    debugger::disassembleChunk(chunk2, "my_chunk");


    return 0;
}