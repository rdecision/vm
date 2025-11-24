#include "core/chunk.h"
#include "core/VirtualMachine.h"
#include "debugger/debugger.h"


int main() {


    Chunk chunk2;
    size_t constant = chunk2.addConstant(1.2);
    chunk2.writeChunk(OP_CONSTANT, 123);
    chunk2.writeChunk(constant, 123);
    constant = chunk2.addConstant(3.4);
    chunk2.writeChunk(OP_CONSTANT, 123);
    chunk2.writeChunk(constant, 123);

    chunk2.writeChunk(OP_ADD, 123);

    constant = chunk2.addConstant(5.6);
    chunk2.writeChunk(OP_CONSTANT, 123);
    chunk2.writeChunk(constant, 123);

    chunk2.writeChunk(OP_DIVIDE, 123);
    chunk2.writeChunk(OP_NEGATE, 123);
    chunk2.writeChunk(OP_RETURN, 123);
    auto vm = VirtualMachine(chunk2);
    vm.interpret();


    return 0;
}