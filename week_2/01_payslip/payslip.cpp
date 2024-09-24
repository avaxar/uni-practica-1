#include <bits/stdc++.h>


struct Employee {
    std::string name;

    // Uses cents instead of rupiah
    uint64_t gross_salary;
    uint64_t tax;
    uint64_t installment;
    uint64_t insurance;
    uint64_t net_salary;
};

bool calculateNet(Employee& employee) {
    employee.tax = employee.gross_salary / 5; // 20%
    uint64_t deductions = employee.tax + employee.installment + employee.insurance;

    // If the deductions are higher than what the employee has earned
    if (deductions > employee.gross_salary) {
        employee.net_salary = 0;
        return false;
    }
    else {
        employee.net_salary = employee.gross_salary - deductions;
        return true;
    }
}

std::string formatMoney(uint64_t cents) {
    std::string original = std::to_string(cents);
    // The formatted string is constructed backwards.
    std::string formatted = "00,0";

    for (size_t i = 0; i < original.length(); i++) {
        char digit = original[original.length() - i - 1];

        // Cents before the comma
        if (i < 2) {
            formatted[i] = digit;
        }
        // First 10^0 digit, replacing '0'
        else if (i == 2) {
            formatted[3] = digit;
        }
        // The rest, where digits must be appended
        else {
            // Add a thousands-separator
            if ((i - 2) % 3 == 0) {
                formatted += '.';
            }

            formatted += digit;
        }
    }

    std::reverse(formatted.begin(), formatted.end());
    return "Rp " + formatted;
}

std::string formatPayslip(const Employee& employee) {
    std::string title = "Payslip for Employee";
    std::vector<std::string> lines = // Payslip information
        {"Name         : " + employee.name,
         "Gross Salary : " + formatMoney(employee.gross_salary),
         "Tax (20%)    : " + formatMoney(employee.tax),
         "Installment  : " + formatMoney(employee.installment),
         "Insurance    : " + formatMoney(employee.insurance),
         "Net Salary   : " + formatMoney(employee.net_salary)};

    // Figures out the maximum amount of characters needed in width
    size_t max_width =
        std::max_element(lines.begin(), lines.end(), [](std::string& a, std::string& b) {
            return a.length() < b.length();
        })->length();
    max_width = std::max(max_width, title.length());

    std::string formatted;
    formatted.reserve((max_width + 5) * (lines.size() + 4) + 1);

    formatted += " -" + std::string(max_width, '-') + "- \n";                          // Top border
    formatted += "| " + title + std::string(max_width - title.length(), ' ') + " |\n"; // Title
    formatted += "|-" + std::string(max_width, '-') + "-|\n";                          // Separator

    for (const std::string& line : lines) {
        formatted += "| " + line + std::string(max_width - line.length(), ' ') + " |\n";
    }

    formatted += " -" + std::string(max_width, '-') + "- \n"; // Bottom border

    return formatted;
}

int program(std::istream& cin, std::ostream& cout) {
    Employee employee;
    cout << "Insert name: ";
    std::getline(cin, employee.name);

    cout << "Insert gross salary: ";
    cin >> employee.gross_salary;
    employee.gross_salary *= 100;

    cout << "Insert installment: ";
    cin >> employee.installment;
    employee.installment *= 100;

    cout << "Insert insurance cost: ";
    cin >> employee.insurance;
    employee.insurance *= 100;

    if (!calculateNet(employee)) {
        cout << "The deductions are higher than the gross salary!\n";
        return 1;
    }

    cout << '\n' << formatPayslip(employee);

    return 0;
}

int main() {
#ifndef TEST
    return program(std::cin, std::cout);
#else
    std::cout << "[*] The program is currently in test mode!\n";

    std::ifstream tests("tests.txt", std::ios::binary);
    if (!tests) {
        std::cout << "[*] Unable to locate `tests.txt` file!\n";
        return 1;
    }

    size_t test_i = 1, test_failures = 0;
    for (std::string line; std::getline(tests, line, '\n');) {
        if (line != "\%INPUT") {
            continue;
        }

        std::string input;
        for (std::string line; std::getline(tests, line, '\n');) {
            if (line == "\%OUTPUT") {
                break;
            }

            input += line + '\n';
        }

        std::string expected_output;
        for (std::string line; std::getline(tests, line, '\n');) {
            if (line == "\%END") {
                break;
            }

            expected_output += line + '\n';
        }

        std::cout << "\n[*] Running test #" << test_i << " with the input...\n" << input;
        std::istringstream pseudo_cin(input);
        std::ostringstream pseudo_cout;
        program(pseudo_cin, pseudo_cout);

        std::string output = pseudo_cout.str();
        if (output == expected_output) {
            std::cout << "[*] Test ran successfully.\n";
        }
        else {
            test_failures++;
            std::cout << "[*] Test failed! Dumping output...\n" << output;
            std::cout << "[*] Output did not match what was expected below.\n" << expected_output;
        }

        test_i++;
    }

    if (test_failures > 0) {
        std::cout << "\n[*] " << test_failures << " test(s) failed in total.\n";
        return 1;
    }
    else {
        std::cout << "\n[*] All tests passed.\n";
        return 0;
    }
#endif
}
