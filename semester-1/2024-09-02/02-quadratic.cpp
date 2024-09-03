#include <cmath>
#include <iostream>


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

void tests();
int main() {
#ifdef TESTS
    tests();
    return 0;
#endif

    double a, b, c;
    std::cout << "Insert `a`: ";
    std::cin >> a;
    std::cout << "Insert `b`: ";
    std::cin >> b;
    std::cout << "Insert `c`: ";
    std::cin >> c;

    double x1, x2;
    switch (quadratic(a, b, c, x1, x2)) {
        case RootType::DISTINCT:
            std::cout << "There are two distinct real roots: " << x1 << " and " << x2 << '\n';
            break;

        case RootType::SINGLE:
            std::cout << "There is only one single real root: " << x1 << '\n';
            break;

        case RootType::COMPLEX:
            std::cout << "There are no real roots; the roots are complex.\n";
            break;
    }

    return 0;
}

#include <cassert>
void tests() {
    std::cout << "[*] Commencing test #1A...\n";
    {
        double x1, x2;
        RootType type = quadratic(1, 0, -1, x1, x2);

        assert(type == RootType::DISTINCT);
        assert(x1 == 1.0);
        assert(x2 == -1.0);
    }
    std::cout << "[*] Test #1A succeeded.\n";

    std::cout << "[*] Commencing test #1B...\n";
    {
        double x1, x2;
        RootType type = quadratic(-2, 4, 6, x1, x2);

        assert(type == RootType::DISTINCT);
        assert(x1 == -1.0);
        assert(x2 == 3.0);
    }
    std::cout << "[*] Test #1B succeeded.\n";

    std::cout << "[*] Commencing test #2A...\n";
    {
        double x1, x2;
        RootType type = quadratic(1, 2, 1, x1, x2);

        assert(type == RootType::SINGLE);
        assert(x1 == -1.0);
        assert(x2 == -1.0);
    }
    std::cout << "[*] Test #2A succeeded.\n";

    std::cout << "[*] Commencing test #2B...\n";
    {
        double x1, x2;
        RootType type = quadratic(-4, -4, -1, x1, x2);

        assert(type == RootType::SINGLE);
        assert(x1 == -0.5);
        assert(x2 == -0.5);
    }
    std::cout << "[*] Test #2B succeeded.\n";

    std::cout << "[*] Commencing test #3A...\n";
    {
        double x1, x2;
        RootType type = quadratic(100, 200, 400, x1, x2);

        assert(type == RootType::COMPLEX);
        assert(isnanf(x1));
        assert(isnanf(x2));
    }
    std::cout << "[*] Test #3A succeeded.\n";

    std::cout << "[*] Commencing test #3B...\n";
    {
        double x1, x2;
        RootType type = quadratic(-400, -200, -100, x1, x2);

        assert(type == RootType::COMPLEX);
        assert(isnanf(x1));
        assert(isnanf(x2));
    }
    std::cout << "[*] Test #3B succeeded.\n";
}
