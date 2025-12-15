#ifndef VM_FILE_IO_H
#define VM_FILE_IO_H

#include <filesystem>
#include <fstream>

namespace file_io {
    void runFile(const std::filesystem::path& path);
    std::string loadFile(const std::filesystem::path& path);
}

#endif //VM_FILE_IO_H