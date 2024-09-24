#include <bits/stdc++.h>


enum class RootType { DISTINCT, SINGLE, COMPLEX };

RootType quadratic(double a, double b, double c, double& x1, double& x2) {
    double discriminant = std::pow(b, 2.0) - 4.0 * a * c;

    // There are two distinct real roots.
    if (discriminant > 0.0) {
        x1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        x2 = (-b - std::sqrt(discriminant)) / (2.0 * a);

        return RootType::DISTINCT;
    }
    // There is only one single real root.
    else if (discriminant == 0.0) {
        // Assigns both output arguments with the same value
        x1 = x2 = -b / (2.0 * a);

        return RootType::SINGLE;
    }
    // The roots are non-real/complex.
    else {
        // Sets both output arguments to NaN
        x1 = x2 = NAN;

        return RootType::COMPLEX;
    }
}

int program(std::istream& cin, std::ostream& cout) {
    double a, b, c;
    cout << "Insert `a`: ";
    cin >> a;
    cout << "Insert `b`: ";
    cin >> b;
    cout << "Insert `c`: ";
    cin >> c;

    double x1, x2;
    switch (quadratic(a, b, c, x1, x2)) {
        case RootType::DISTINCT:
            cout << "\nThere are two distinct real roots: " << x1 << " and " << x2 << ".\n";
            break;

        case RootType::SINGLE:
            cout << "\nThere is only one single real root: " << x1 << ".\n";
            break;

        case RootType::COMPLEX:
            cout << "\nThere are no real roots; the roots are complex.\n";
            break;
    }

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
