#pragma once
#include <string>
#include <string_view>

class Compiler {
    std::string_view inputPath  {};
    std::string_view outputPath {};

    const char* const buildPath = "/build/";
    const char* const binPath = "/bin/";

    bool hasFailed = false;
public:
    Compiler(
        const std::string_view& inputPath,
        const std::string_view& outputPath
    );

    Compiler() = default;
    ~Compiler() = default;

    auto compile()    -> int;    
    auto lexer()      -> void;
    auto parser()     -> void;
    auto resolver()   -> void;
    auto optimizer()  -> void;
    auto transpiler() -> void;

    auto isFailed() -> bool;
};