#include "debugger/debugger.h"
#include "core/value.h"
#include <iostream>
#include <iomanip>

namespace debugger {
    void disassembleChunk(const Chunk& chunk, std::string_view name) {
        //TODO: implement stringstream version instead?
        std::cout << "== " << name << " ==" << std::endl;

        for (int offset = 0; offset < chunk.getChunkSize();) {
            offset = disassembleInstruction(chunk, offset);
        }
    }

    int disassembleInstruction(const Chunk& chunk, const int offset) {
        std::cout << std::setfill('0')  << std::setw(4) << offset << " ";
        if (offset > 0 && chunk.getLine(offset) == chunk.getLine(offset - 1)) {
            std::cout <<  "   | ";
        }
        else {
            std::cout << std::setfill('0')  << std::setw(4) << chunk.getLine(offset) << " ";
        }
        switch (chunk.readChunk(offset)) {
            case OP_RETURN:
                return simpleInstruction("OP_RETURN", offset);
            case OP_CONSTANT:
                return constantInstruction("OP_CONSTANT", chunk, offset);
            default:
                std::cout << "Unknown instruction" << std::endl;
                return offset + 1;

        }
    }

    int simpleInstruction(const std::string_view name, const int offset) {
        std::cout << name << std::endl;
        return offset + 1;
    }

    int constantInstruction(const std::string_view name, const Chunk& chunk, const int offset) {
        uint8_t constant = chunk.readChunk(offset + 1);
        std::cout << name << constant;
        printValue(chunk.readConstant(constant));
        std::cout << "'\n";
        return offset + 2;

    }

    void printValue(Value value) {
        std::cout << value;
    }

}