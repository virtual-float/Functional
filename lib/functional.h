#pragma once
#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <string>
#include <string_view>
#include <sstream>

// Functional's Macros for testing
#define __virtualf_lib_functional


// 'func' namespace
namespace func
{
    /**
     * * Checks if a value is in the array
     * @param Array& Array
     * @param Iterator begin
     * @param Iterator end
     * @return True if in array, otherwise false
     */
    template<class Array, typename Iterator, typename Value>
    inline constexpr bool in(Array& array, Iterator begin, Iterator end, const Value& value) {
        // Iterate
        while (begin != end) {
            // If the value doesn\'t exist - return false 
            if (*begin == value) return true;

            // Increment the begin iterator
            ++begin;
        }

        return false;
    }

    /**
     * * Checks if each element is true/not equal to NULL
     * @param Array& Array
     * @param Iterator Array's begin iterator
     * @param Iterator Array's end iterator
     * @return False if any element is false/equal to NULL, otherwise true
     */
    template<class Array, typename Iterator>
    inline bool all(Array& array, Iterator begin, Iterator end) {
        // Iterate
        while (begin != end) {
            // If the value doesn\'t exist - return false 
            if (!(*begin)) return false;

            // Increment the begin iterator
            ++begin;
        }

        return true;
    }

    /**
     * * Checks if any element is true/not equal to NULL
     * @param Array& Array
     * @param Iterator Array's begin iterator
     * @param Iterator Array's end iterator
     * @return True if any element is true/not equal to NULL, otherwise False
     */
    template<class Array, typename Iterator>
    inline bool any(Array& array, Iterator begin, Iterator end) {
        // Iterate
        while (begin != end) {
            // If the value does exist - return true 
            if (*begin) return true;

            // Increment the begin iterator
            ++begin;
        }

        return false;
    }

    /**
     * * Eleminates every occurenced character from the string
     * @param std::string_view String to search in
     * @param char Delimiter
     * @return Filtered string
     */
    std::string eleminate(const std::string_view victim, char delimiter);
    
    /**
     * * Prints all array's elements in one line with separating
     * @param Array& Array
     * @param Iterator Array's begin iterator
     * @param Iterator Array's end iterator
     * @param char Separator
     * @return Formatted string
     */
    template<class Array, typename Iterator>
    inline std::string print_array(Array& array, Iterator begin, Iterator end, char separator = ' ') {
        std::stringstream ss;

        // Iterate
        while (begin != end) {
            // Pass value and separator to the stringstream
            ss << *begin << separator;

            // Increment the begin iterator
            ++begin;
        }

        // Return string 
        return ss.str();
    }

    /**
     * * Checks if the array does not have any duplicates
     * @param Array& Array
     * @param Iterator Array's begin iterator
     * @param Iterator Array's end iterator
     * @return True if does not contain any duplicates, otherwise false
     */
    template<class Array, typename Iterator>
    inline bool is_unique(Array& array, Iterator begin, Iterator end) {
        // Iterate
        while (begin != end) {
            // If found, return false
            if (func::in(array, std::next(begin), end, *begin)) return false;

            // Increment the begin iterator
            ++begin;
        }

        return true;
    }
}


#endif // FUNCTIONAL_HXX