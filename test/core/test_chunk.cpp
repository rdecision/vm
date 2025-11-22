#include "test_chunk.h"
#include "gtest/gtest.h"

TEST(Chunk, DefaultConstructedIsEmpty) {
    Chunk chunk;
    EXPECT_EQ(chunk.getChunkSize(), 0);
}

TEST(Chunk, WriteChunkWorksForSimpleOp) {
    Chunk chunk;
    chunk.writeChunk(OP_RETURN, 123);
    ASSERT_EQ(chunk.readChunk(0), OP_RETURN);
}

TEST(Chunk, WriteChunkWorksForConstOp) {
    Chunk chunk;
    size_t constant = chunk.addConstant(1.2);
    chunk.writeChunk(OP_CONSTANT, 123);
    chunk.writeChunk(constant, 123);
    ASSERT_EQ(chunk.readChunk(0), OP_CONSTANT);
    ASSERT_EQ(constant, 0);
}

TEST(Chunk, DisassembleChunkOutput) {

}