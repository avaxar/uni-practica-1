#include "../../preamble.h"


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
    // If it is equal or below zero, just print "0 = 0".
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
