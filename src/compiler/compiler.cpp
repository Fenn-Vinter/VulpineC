#include <compiler.hpp>
#include <format>
#include <metadata.hpp>

#include <filesystem>
#include <print>

namespace fs = std::filesystem;

auto Compiler::isFailed() -> bool { return this->hasFailed; }

Compiler::Compiler(
    const std::string_view& inputPath,
    const std::string_view& outputPath
) {
    if (fs::exists(inputPath))
        if (fs::is_regular_file(inputPath)) this->inputPath = inputPath;
        else {
            std::println("First arguement must be path to a valid Vulpine file {} file.vlp", metadata::engineName);
            this->hasFailed = true;
        }
    else {
        std::println("Invalid path, file does not exist {}\n", inputPath);
        this->hasFailed = true;
    }

    if (!fs::is_directory(outputPath))
        fs::create_directory(outputPath);
    
    if (!fs::exists(std::string(outputPath) + buildPath))
        fs::create_directory(std::string(outputPath) + buildPath);

    if (!fs::exists(std::string(outputPath) + binPath))
        fs::create_directory(std::string(outputPath) + binPath);

    this->outputPath = outputPath;
}