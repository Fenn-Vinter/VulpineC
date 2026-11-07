#pragma once

#include <token.hpp>

#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

enum class Severity {
    INFO,
    SUGGESTION,
    CORRECTION,
    FORMATTING,
    WARN,
    ERROR,
    CRITICAL
};

struct DiagnosticNote {
    size_t pos{0UL};
    size_t len{0UL};
    std::string msg{""};
};

struct Error {
    size_t pos{0UL};
    size_t len{0UL};
    uint32_t code{0U};
    std::string path{""};
    std::string msg{""};
    std::vector<DiagnosticNote> notes{};
    Severity severity{Severity::INFO};

    Error(Token token) {
        this->pos = token.pos;
        this->len = token.len;
    }
};

struct CompilerError {
    Severity severity{Severity::CRITICAL};
    uint32_t code{0U};
    std::string msg{""};
    std::vector<std::string> extra_info;
};

class Diagnostics {
    std::vector<Error> Vulpine_Errors{};
    std::vector<CompilerError> Internal_Errors{};
public:
    Diagnostics()  = default;
    ~Diagnostics() = default;

    auto report(Error err) -> void {
        Vulpine_Errors.push_back(std::move(err));
    }

    auto internal_fail(CompilerError err) -> void {
        Internal_Errors.push_back(std::move(err));
    }

    [[nodiscard]] bool has_errors() const {
        for (const auto& err : Vulpine_Errors) {
            if (err.severity == Severity::ERROR || err.severity == Severity::CRITICAL) {
                return true;
            }
        }
        return !Internal_Errors.empty();
    }
    
    [[nodiscard]] const std::vector<Error>& get_errors() const { return Vulpine_Errors; }
    [[nodiscard]] const std::vector<CompilerError>& get_internal_errors() const { return Internal_Errors; }

    void clear() {
        Vulpine_Errors.clear();
        Internal_Errors.clear();
    }
};
