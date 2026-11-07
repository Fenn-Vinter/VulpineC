#pragma once

class File {
    void* _begin {nullptr};
    void* _end {nullptr};
public:
    File(void* begin, void* end) {
        this->_begin = begin;
        this->_end = end; 
    }

    File() = default;
   ~File() = default;

    auto begin() -> void* { return this->_begin; };
    auto end()   -> void* { return this->_end; }
};
