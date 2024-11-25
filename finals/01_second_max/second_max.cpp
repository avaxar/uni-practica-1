#include <bits/stdc++.h>


int64_t secondMax(const std::vector<int64_t>& numbers) {
    // Prerequisite variables: sets them as low as possible
    int64_t first = std::numeric_limits<int64_t>::min();
    int64_t second = first;

    // Loops through every number
    for (int64_t num : numbers) {
        // If exceeds the max, dethrones it
        if (num > first) {
            second = first; // Former max gets demoted.
            first = num;
        }
        // If exceeds the second max, dethrones it
        else if (num > second) {
            second = num;
        }
    }

    return second;
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

    std::cout << "The second largest number is " << secondMax(numbers) << ".\n";
    return 0;
}
// Test mode
#else
int main() {
    std::cout << "The program is running on testing mode...\n";
    int failures = 0;

    // Test #1
    if (secondMax({1, 2, 3, 4, 5}) != 4) {
        failures++;
        std::cout << "Test #1 failed!\n";
    }

    // Test #2
    if (secondMax({8234, 324, 323, 1239, 4523, 1392}) != 4523) {
        failures++;
        std::cout << "Test #2 failed!\n";
    }

    // Test #3
    if (secondMax({-999999, 3129, 54240, 123}) != 3129) {
        failures++;
        std::cout << "Test #3 failed!\n";
    }

    // Test #4
    if (secondMax({0, -1, -2, -3, -4, -5, -6, -7, -8, -999}) != -1) {
        failures++;
        std::cout << "Test #4 failed!\n";
    }

    // Test #5
    if (secondMax({-2, -3, -4, -1, 0, 1}) != 0) {
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
