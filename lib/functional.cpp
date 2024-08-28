#include "functional.h"

std::string func::eliminate(const std::string_view victim, char delimiter) {
    std::stringstream ss;

    // Iterate
    for (const char& ch : victim) {
        if (ch == delimiter) continue;
        // Pass character to stringstream
        ss << ch;
    }

    // Return string
    return ss.str();
}