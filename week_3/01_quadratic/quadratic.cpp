/*
 * For some reason, this assignment is perfectly identical with the assignment given in the second
 * problem of the second week. In this version, I simplified the algorithm down as to fit it all in
 * one single function.
 */

#include "../../preamble.h"


int program(std::istream& cin, std::ostream& cout) {
    double a, b, c;
    cout << "Insert `a`: ";
    cin >> a;
    cout << "Insert `b`: ";
    cin >> b;
    cout << "Insert `c`: ";
    cin >> c;

    double discriminant = std::pow(b, 2.0) - 4.0 * a * c;
    // If D > 0, then both roots are distinct and real.
    if (discriminant > 0) {
        double x1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2.0 * a);

        cout << "\nThe roots are distinct: " << x1 << " and " << x2 << ".\n";
    }
    // If D == 0, then both roots are the same.
    else if (discriminant == 0) {
        double x = (-b + std::sqrt(discriminant)) / (2.0 * a);

        cout << "\nThere is only one real root: " << x << ".\n";
    }
    // If D < 0, then no real roots exist.
    else {
        cout << "\nThe roots are imaginary.\n";
    }

    return 0;
}
