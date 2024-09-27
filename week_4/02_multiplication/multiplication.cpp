#include "../../preamble.h"


int program(std::istream& cin, std::ostream& cout) {
    int64_t n;
    cout << "Input: ";
    cin >> n;

    cout << "\n[Multiplication Table]\n";
    for (int64_t i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << (n * i) << '\n';
    }

    return 0;
}
