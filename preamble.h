/*
 * This file handles with the inclusion of all STL functionalities and provides a system for test
 * cases for each practicum problem, as to cut down on the repetition of code.
 */

#include <bits/stdc++.h>


int program(std::istream& cin, std::ostream& cout);

int main() {
    // For consistent formatting through streams
    std::setlocale(LC_ALL, "en_US.UTF-8");

#ifndef TEST
    // Normal execution of the program through manual user input
    return program(std::cin, std::cout);
#else
    // Test mode through the TEST macro enabled from the compiler by `-DTESTS`
    std::cout << "[*] The program is currently in test mode!\n";

    // The test cases are stored in a `tests.txt` file.
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
