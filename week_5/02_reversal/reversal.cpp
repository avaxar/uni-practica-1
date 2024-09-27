#include "../../preamble.h"


int program(std::istream& cin, std::ostream& cout) {
    cout << "Input: ";
    std::vector<int64_t> vec;
    char inp;

    // Clears any whitespace
    do {
        cin >> inp;
    } while (std::isspace(inp));

    // Expects an opening square bracket for the vector
    if (inp != '[') {
        cout << "Expected an opening square bracket!\n";
        return 1;
    }

    // Clears any whitespace
    do {
        cin >> inp;
    } while (std::isspace(inp));

    // Loops until the array is closed
    while (inp != ']') {
        // The latter condition also handles negative numbers
        if (!('0' <= inp && inp <= '9') && inp != '-') {
            cout << "Expected a number, but instead saw '" << inp << "'!\n";
            return 1;
        }

        // Returns the checked character and reads for the integer
        cin.unget();
        vec.push_back(0);
        cin >> vec[vec.size() - 1];

        // Clears any whitespace
        do {
            cin >> inp;
        } while (std::isspace(inp));

        // Hints that the vector has ended
        if (inp == ']') {
            break;
        }

        if (inp != ',') {
            cout << "Expected a comma, but instead saw '" << inp << "'!\n";
            return 1;
        }

        // Clears any whitespace
        do {
            cin >> inp;
        } while (std::isspace(inp));
    }

    // Reverses the vector
    std::vector<int64_t> reversed;
    reversed.reserve(vec.size()); // So that the vector doesn't need to reallocate
    for (size_t i = vec.size() - 1; i < vec.size(); i--) { // Iterates backwards
        reversed.push_back(vec[i]);
    }

    // Prints the content of the reversed vector
    cout << "Output: [";
    for (size_t i = 0; i < reversed.size(); i++) {
        cout << reversed[i];
        if (i < reversed.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}
