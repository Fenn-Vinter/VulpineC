#include "lsp.hpp"
#include <print>

#include <metadata.hpp>
#include <string_view>
#include <compiler.hpp>

auto print_help() -> void {
    std::println("usage:");
    std::println("{} starts the Vulpine LSP", metadata::engineName);
    std::println("{} <src.vlp> --Compiles the vulpine sourcefile", metadata::engineName);
    std::println("{} <src.vlp> <path> --Compiles the vulpine sourcefile and puts the bin and build folder into the new path", metadata::engineName);
}

auto main(int argc, char* argv[]) -> int {
    std::println("{} v{} initialized.", metadata::engineName, metadata::version);

    if (argc < 2) {
        LSP lsp{};
        return lsp.main();
    } else {
        if (std::string_view(argv[1]) == "help") {
            print_help();
            return 0;
        }

        Compiler compiler{
            argv[1],
            (argc > 2) ? argv[2] : ""
        };

        return compiler.compile();
    }

    return 0;
}