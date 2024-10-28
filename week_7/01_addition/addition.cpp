#include "../../preamble.h"


// Requirement: an addition function
double add(double a, double b) {
    return a + b;
}

int program(std::istream& cin, std::ostream& cout) {
    double a;
    cout << "a = ";
    cin >> a;

    double b;
    cout << "b = ";
    cin >> b;

    cout << "\nadd(" << a << ", " << b << ") = " << add(a, b) << '\n';
    return 0;
}
