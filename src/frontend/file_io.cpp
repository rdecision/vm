#include "frontend/file_io.h"


std::string file_io::loadFile(const std::filesystem::path& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Could not open file" + path.string());
    }
    return {std::streambuf<char>(file), {}};
}