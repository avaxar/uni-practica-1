#include <iostream>


int main() {
    double n1, n2, n3;
    std::cout << "Input the first number: ";
    std::cin >> n1;
    std::cout << "Input the second number: ";
    std::cin >> n2;
    std::cout << "Input the third number: ";
    std::cin >> n3;

    // Generally, using a loop to iterate over all of the remaining elements within an array to
    // check the maximum would be better, in order to reduce code duplication. However, since there
    // are only three elements in total, stored in separate variables, unwound if-statements are
    // used instead.
    double max = n1;
    if (n2 > max) {
        max = n2;
    }
    if (n3 > max) {
        max = n3;
    }

    std::cout << "The maximum is " << max << ".\n";
    return 0;
}
