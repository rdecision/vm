#ifndef clox_chunk_h
#define clox_chunk_h

#include <vector>

using std::vector;

enum class OpCode {
    OP_RETURN,
};

class Chunk {
    private:
        vector<OpCode> code;
    public:
        Chunk();
        void writeChunk(OpCode byte);
};


#endif