#include "../../preamble.h"


int program(std::istream& cin, std::ostream& cout) {
    // Requirement: the use of std::vector
    std::vector<std::string> result;
    result.reserve(100); // So that the vector doesn't need to reallocate

    for (int i = 1; i <= 100; i++) {
        // Both multiples of 3 and 5
        if (i % 3 == 0 && i % 5 == 0) {
            result.push_back("FizzBuzz");
        }
        // Only a multiple of 3
        else if (i % 3 == 0) {
            result.push_back("Fizz");
        }
        // Only a multiple of 5
        else if (i % 5 == 0) {
            result.push_back("Buzz");
        }
        // If neither
        else {
            result.push_back(std::to_string(i));
        }
    }

    // Prints each element in the final vector
    for (std::string& str : result) {
        cout << "- " << str << '\n';
    }

    return 0;
}
