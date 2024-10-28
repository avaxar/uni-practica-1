#include "../../preamble.h"


uint64_t factorial(uint64_t n) {
    // Base case: 0! = 1
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

int program(std::istream& cin, std::ostream& cout) {
    uint64_t n;
    cout << "n = ";
    cin >> n;

    cout << "\nfactorial(" << n << ") = " << factorial(n) << '\n';
    return 0;
}
