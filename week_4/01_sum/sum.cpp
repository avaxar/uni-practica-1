#include <bits/stdc++.h>


int program(std::istream& cin, std::ostream& cout) {
    int64_t n;
    cout << "Input: ";
    cin >> n;

    int64_t val = 0;
    for (int64_t i = 1; i <= n; i++) {
        val += i;
    }

    cout << "Output: " << val << '\n';

    cout << "(Explanation: ";
    if (n <= 0) {
        cout << "0";
    }
    for (int64_t i = 1; i <= n; i++) {
        cout << i;
        if (i != n) {
            cout << " + ";
        }
    }
    cout << " = " << val << ")\n";

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
