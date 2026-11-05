#include <cstddef>
#include <iostream>
#include <print>

#include <metadata.hpp>
#include <stop_token>
#include <string>
#include <string_view>

constexpr std::string_view OUTPUT_ARG   = "-o";
constexpr std::string_view LSP_ARG      = "-lsp";

std::string sourceFile {};

auto lsp() -> int {
    
}

auto compile(std::stop_token stoken) -> void {
    std::println("[{}] Compiling {}", metadata::engineName, sourceFile);

    if (stoken.stop_requested()) {
        std::println("[{}] Compilation cancelled.", metadata::engineName);
        return;
    }

    std::println("[{}] Compilation finished successfully.", metadata::engineName);
}

auto print_help() -> void {
    std::println("usage:");
    std::println("{} <src.vlp> --Compiles the vulpine sourcefile", metadata::engineName);
    std::println("{} <rootpath> {} --Starts the language server and sets rootpath", metadata::engineName, LSP_ARG);
    std::println("{} lets you define a different folder to collect build and bin files", OUTPUT_ARG);
}

auto main(int argc, char* argv[]) -> int {
    std::println("{} v{} initialized.", metadata::engineName, metadata::version);

    if (argc < 2) {
        print_help();
        return 1;
    }

    return 0;
}