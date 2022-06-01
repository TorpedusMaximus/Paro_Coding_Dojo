#pragma once
#include <vector>

struct Memory final {
    using MemoryCell = unsigned char;

    MemoryCell get() const { return memory_[*it_]; }

    void set(MemoryCell const value) { memory_[*it_] = value; }

    void increment() { memory_[*it_] += 1; }

    void decrement() { memory_[*it_] -= 1; }

    void moveLeft() { it_--; }

    void moveRight() { it_++; }

    Memory()
        : memory_(2000, 0)
        , it_(memory_.begin() + (memory_.size() / 2)) {
    }

    Memory(Memory const&) = delete;
    Memory& operator=(Memory const&) = delete;

private:
    using MemoryCells = std::vector<MemoryCell>;
    MemoryCells memory_;
    MemoryCells::iterator it_;
};
