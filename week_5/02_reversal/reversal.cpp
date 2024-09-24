#include <bits/stdc++.h>


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
        if (!('0' <= inp && inp <= '9') && inp != '-') {
            cout << "Expected a number, but instead saw '" << inp << "'!\n";
            return 1;
        }

        cin.unget();
        vec.push_back(0);
        cin >> vec[vec.size() - 1];

        // Clears any whitespace
        do {
            cin >> inp;
        } while (std::isspace(inp));

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
    reversed.reserve(vec.size());
    for (size_t i = vec.size() - 1; i < vec.size(); i--) {
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

int main() {
#ifndef TEST
    return program(std::cin, std::cout);
#else
    std::cout << "[*] The program is currently in test mode!\n";

    std::ifstream tests("tests.txt", std::ios::binary);
    if (!tests) {
        std::cout << "[*] Unable to locate `tests.txt` file!\n";
        return 1;
    }

    size_t test_i = 1, test_failures = 0;
    for (std::string line; std::getline(tests, line, '\n');) {
        if (line != "\%INPUT") {
            continue;
        }

        std::string input;
        for (std::string line; std::getline(tests, line, '\n');) {
            if (line == "\%OUTPUT") {
                break;
            }

            input += line + '\n';
        }

        std::string expected_output;
        for (std::string line; std::getline(tests, line, '\n');) {
            if (line == "\%END") {
                break;
            }

            expected_output += line + '\n';
        }

        std::cout << "\n[*] Running test #" << test_i << " with the input...\n" << input;
        std::istringstream pseudo_cin(input);
        std::ostringstream pseudo_cout;
        program(pseudo_cin, pseudo_cout);

        std::string output = pseudo_cout.str();
        if (output == expected_output) {
            std::cout << "[*] Test ran successfully.\n";
        }
        else {
            test_failures++;
            std::cout << "[*] Test failed! Dumping output...\n" << output;
            std::cout << "[*] Output did not match what was expected below.\n" << expected_output;
        }

        test_i++;
    }

    if (test_failures > 0) {
        std::cout << "\n[*] " << test_failures << " test(s) failed in total.\n";
        return 1;
    }
    else {
        std::cout << "\n[*] All tests passed.\n";
        return 0;
    }
#endif
}
