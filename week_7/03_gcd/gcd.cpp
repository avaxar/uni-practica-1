#include "../../preamble.h"


// Implements the Euclidean algorithm
uint64_t gcd(uint64_t a, uint64_t b) {
    // Base case: gcd(a, 0) = a
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int program(std::istream& cin, std::ostream& cout) {
    uint64_t a;
    cout << "a = ";
    cin >> a;

    uint64_t b;
    cout << "b = ";
    cin >> b;

    cout << "\ngcd(" << a << ", " << b << ") = " << gcd(a, b) << '\n';
    return 0;
}
