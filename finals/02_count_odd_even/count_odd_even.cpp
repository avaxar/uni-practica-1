#include <bits/stdc++.h>


void count(const std::vector<int64_t>& numbers, size_t& odds, size_t& evens) {
    odds = 0;
    evens = 0;

    // Loops through every number
    for (int64_t num : numbers) {
        // If even
        if (num % 2 == 0) {
            evens++;
        }
        // If odd
        else {
            odds++;
        }
    }
}

// Normal running mode
#ifndef TEST
int main() {
    // Requests for the amount of numbers
    size_t n;
    std::cout << "Enter the number of number(s): ";
    std::cin >> n;

    // Terminates early if no elements
    if (n == 0) {
        std::cout << "Expected to be more than zero.\n";
        return 1;
    }

    // Receives input for the numbers
    std::vector<int64_t> numbers(n);
    std::cout << "Input your numbers: ";
    for (size_t i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    // Counts the amount of odd and even numbers
    size_t odds, evens;
    count(numbers, odds, evens);


    std::cout << "There are " << odds << " odd number(s) and " << evens << " even number(s).\n";
    return 0;
}
// Test mode
#else
int main() {
    std::cout << "The program is running on testing mode...\n";
    int failures = 0;

    size_t odds, evens;

    // Test #1
    count({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, odds, evens);
    if (odds != 5 || evens != 5) {
        failures++;
        std::cout << "Test #1 failed!\n";
    }

    // Test #2
    count({13289, 123987, 98234, 32478, 123789, 54312, 213980, 4503, 341980, 42978}, odds, evens);
    if (odds != 4 || evens != 6) {
        failures++;
        std::cout << "Test #2 failed!\n";
    }

    // Test #3
    count({0, 2, 4, 6, 10, 12, 14, 16, 18, 20}, odds, evens);
    if (odds != 0 || evens != 10) {
        failures++;
        std::cout << "Test #3 failed!\n";
    }

    // Test #4
    count({-1, 1, 3, 5, 7, 9, 11, 13, 15, 17}, odds, evens);
    if (odds != 10 || evens != 0) {
        failures++;
        std::cout << "Test #4 failed!\n";
    }

    // Test #5
    count({0, 1, -2, 3, -4, 5, -6, 7, -8, 9}, odds, evens);
    if (odds != 5 || evens != 5) {
        failures++;
        std::cout << "Test #5 failed!\n";
    }

    if (failures > 0) {
        std::cout << failures << " test(s) failed.\n";
        return 1;
    }
    else {
        std::cout << "The test case(s) ran successfully\n.";
        return 0;
    }
}
#endif
