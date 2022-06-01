#include "Brainfuck.hpp"
#include "Memory.hpp"

std::string Brainfuck::interpret(Code const& code, Input const& input) const {
    Memory memory;
    std::string result;

    // BRAINFUCK INTERPRETER
    for (auto const& c : code) {
        switch (c) {
            case '>':
                memory.increment();
                break;
            case '<':
                memory.decrement();
                break;
            case '+':
                memory.increment();
                break;
            case '-':
                memory.decrement();
                break;
            case '.':
                result += memory.get();
                break;
            case ',':
                memory.set(input.get());
                break;
            case '[':
                if (memory.get() == 0) {
                    int depth = 1;
                    while (depth > 0) {
                        if (code[++code.getPosition()] == '[') {
                            ++depth;
                        } else if (code[code.getPosition()] == ']') {
                            --depth;
                        }
                    }
                }
                break;
            case ']':
                if (memory.get() != 0) {
                    int depth = 1;
                    while (depth > 0) {
                        if (code[--code.getPosition()] == '[') {
                            --depth;
                        } else if (code[code.getPosition()] == ']') {
                            ++depth;
                        }
                    }
                }
                break;
            default:
                break;
        }
    }

    return result;
}
