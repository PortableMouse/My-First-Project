#pragma once
#include <cstdio>

// myAssert(condition, "message")
// In Debug builds: if the condition is false, prints the message,
// the file and line, then stops the program.
// In Release builds (with NDEBUG defined): does nothing.

#ifndef NDEBUG
    #define myAssert(cond, msg) \
        do { if (!(cond)) { \
            std::fprintf(stderr, "Assert failed: %s\n%s\n%s:%d\n", \
                         #cond, msg, __FILE__, __LINE__); \
            __builtin_trap(); \
        } } while (0)
#else
    #define myAssert(cond, msg) do {} while (0)
#endif
