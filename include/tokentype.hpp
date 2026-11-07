#pragma once

#include <string_view>

enum class TokenType { 
#define X(name, str) name,
#include <vulpine_types.def>
#undef X
};

constexpr auto TokenType_To_Str(TokenType type) -> std::string_view {
    switch (type) {
#define X(name, str) case TokenType::name: return str;
#include <vulpine_types.def>
#undef X
    }
    return "unknown";
}
