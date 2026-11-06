#pragma once
#include <cstddef>
#include <tokentype.hpp>

struct token {
    TokenType type;
    size_t pos;
    size_t len;
};