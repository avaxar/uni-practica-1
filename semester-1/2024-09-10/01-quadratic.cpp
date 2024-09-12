#include <cmath>
#include <iostream>


int main() {
    double a, b, c;
    std::cout << "Insert `a`: ";
    std::cin >> a;
    std::cout << "Insert `b`: ";
    std::cin >> b;
    std::cout << "Insert `c`: ";
    std::cin >> c;

    double discriminant = std::pow(b, 2.0) - 4.0 * a * c;
    // If D > 0, then both roots are distinct and real.
    if (discriminant > 0) {
        double x1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2.0 * a);

        std::cout << "The roots are distinct: " << x1 << " and " << x2 << ".\n";
    }
    // If D == 0, then both roots are the same.
    else if (discriminant == 0) {
        double x = (-b + std::sqrt(discriminant)) / (2.0 * a);

        std::cout << "There is only one real root: " << x << ".\n";
    }
    // If D < 0, then no real roots exist.
    else {
        std::cout << "The roots are imaginary.\n";
    }

    return 0;
}
