#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>


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

void tests();
int main() {
#ifdef TESTS
    tests();
    return 0;
#endif

    Employee employee;
    std::cout << "Insert name: ";
    std::getline(std::cin, employee.name);

    std::cout << "Insert gross salary: ";
    std::cin >> employee.gross_salary;
    employee.gross_salary *= 100;

    std::cout << "Insert installment: ";
    std::cin >> employee.installment;
    employee.installment *= 100;

    std::cout << "Insert insurance cost: ";
    std::cin >> employee.insurance;
    employee.insurance *= 100;

    if (!calculateNet(employee)) {
        std::cout << "The deductions are higher than the gross salary!\n";
        return 1;
    }

    std::cout << '\n' << formatPayslip(employee);

    return 0;
}

#include <cassert>
void tests() {
    {
        Employee employee = {
            .name = "Rick Sanchez",
            .gross_salary = 500000000, // Rp 5.000.000,00
            .installment = 50000000,   // Rp 500.000,00
            .insurance = 25000000,     // Rp 250.000,00
        };

        std::cout << "[*] Commencing test #1A...\n";
        assert(calculateNet(employee) == true);
        assert(employee.tax == 100000000);        // Rp 1.000.000,00
        assert(employee.net_salary == 325000000); // Rp 3.250.000,00
        std::cout << "[*] Test #1A succeeded.\n";

        std::cout << "[*] Commencing test #1B...\n";
        assert(formatPayslip(employee) == " -------------------------------- \n"
                                          "| Payslip for Employee           |\n"
                                          "|--------------------------------|\n"
                                          "| Name         : Rick Sanchez    |\n"
                                          "| Gross Salary : Rp 5.000.000,00 |\n"
                                          "| Tax (20%)    : Rp 1.000.000,00 |\n"
                                          "| Installment  : Rp 500.000,00   |\n"
                                          "| Insurance    : Rp 250.000,00   |\n"
                                          "| Net Salary   : Rp 3.250.000,00 |\n"
                                          " -------------------------------- \n");
        std::cout << "[*] Test #1B succeeded.\n";
    }

    {
        Employee employee = {
            .name = "Paul Muad'Dib Atreides",
            .gross_salary = 200000200, // Rp 2.000.002,00
            .installment = 1000000,    // Rp 10.000,00
            .insurance = 13333333,     // Rp 133.333,33
        };

        std::cout << "[*] Commencing test #2A...\n";
        assert(calculateNet(employee) == true);
        assert(employee.tax == 40000040);         // Rp 400.000,40
        assert(employee.net_salary == 145666827); // Rp 1.456.668,27
        std::cout << "[*] Test #2A succeeded.\n";

        std::cout << "[*] Commencing test #2B...\n";
        assert(formatPayslip(employee) == " --------------------------------------- \n"
                                          "| Payslip for Employee                  |\n"
                                          "|---------------------------------------|\n"
                                          "| Name         : Paul Muad'Dib Atreides |\n"
                                          "| Gross Salary : Rp 2.000.002,00        |\n"
                                          "| Tax (20%)    : Rp 400.000,40          |\n"
                                          "| Installment  : Rp 10.000,00           |\n"
                                          "| Insurance    : Rp 133.333,33          |\n"
                                          "| Net Salary   : Rp 1.456.668,27        |\n"
                                          " --------------------------------------- \n");
        std::cout << "[*] Test #2B succeeded.\n";
    }

    {
        Employee employee = {
            .name = "John Doe",
            .gross_salary = 2000000, // Rp 20.000,00
            .installment = 0,        // Rp 0,00
            .insurance = 100000,     // Rp 1.000,00
        };

        std::cout << "[*] Commencing test #3A...\n";
        assert(calculateNet(employee) == true);
        assert(employee.tax == 400000);         // Rp 4.000,00
        assert(employee.net_salary == 1500000); // Rp 15.000,00
        std::cout << "[*] Test #3A succeeded.\n";

        std::cout << "[*] Commencing test #3B...\n";
        assert(formatPayslip(employee) == " ----------------------------- \n"
                                          "| Payslip for Employee        |\n"
                                          "|-----------------------------|\n"
                                          "| Name         : John Doe     |\n"
                                          "| Gross Salary : Rp 20.000,00 |\n"
                                          "| Tax (20%)    : Rp 4.000,00  |\n"
                                          "| Installment  : Rp 0,00      |\n"
                                          "| Insurance    : Rp 1.000,00  |\n"
                                          "| Net Salary   : Rp 15.000,00 |\n"
                                          " ----------------------------- \n");
        std::cout << "[*] Test #3B succeeded.\n";
    }
}
