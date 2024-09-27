#include "../../preamble.h"


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
