#pragma once
#include <cstddef>
#include <tokentype.hpp>

struct Token {
    TokenType type;
    size_t pos;
    size_t len;
};