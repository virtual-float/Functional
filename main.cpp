#include <iostream>
#include "lib/functional.h"
#include <vector>
#include <list>

int main()
{
    // Example values (vector)
    std::vector<int> values {4, 5, 6, 7, 8, 9};

    // Example values (list)
    std::list<char> chars = {'I', 'L', 'C', '+', '+'};

    // Vector test
    if (func::all(values, values.begin(), values.end())) {
        std::cout << "Vector: all true!" << std::endl;
    } else {
        std::cout << "Vector: not all true!" << std::endl;
    }

    // List test
    if (func::all(chars, chars.begin(), chars.end())) {
        std::cout << "List: all true!" << std::endl;
    } else {
        std::cout << "List: not all true!" << std::endl;
    }

    std::cout << func::eliminate("A bc defghi j klmnop qrst uvwxy z", ' ') << std::endl;
    
    // Vector
    std::cout << func::print_array(values, values.begin(), values.end()) << std::endl;
    // List
    std::cout << func::print_array(chars, chars.begin(), chars.end()) << std::endl;

    const int Number = 7;

    // Vector
    if (func::in(values, values.begin(), values.end(), Number)) {
        std::cout << "Vector: found " + std::to_string(Number) << std::endl;
    } else {
        std::cout << "Vector: not found" << std::endl;
    }

    // List
    if (func::in(chars, chars.begin(), chars.end(), Number)) {
        std::cout << "List: found " + std::to_string(Number) << std::endl;
    } else {
        std::cout << "List: not found!" << std::endl;
    }

    // Vector
    if (func::is_unique(values, values.begin(), values.end())) {
        std::cout << "Vector: Unique!" << std::endl;
    } else {
        std::cout << "Vector: Not unique!" << std::endl;
    }

    // List
    if (func::is_unique(chars, chars.begin(), chars.end())) {
        std::cout << "List: Unique!" << std::endl;
    } else {
        std::cout << "List: Not unique!" << std::endl;
    }

    return 0;
}