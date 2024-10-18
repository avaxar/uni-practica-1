#include "../../preamble.h"


// Requirement: the use of a struct
struct Student {
    std::string id;
    double midterm;
    double final;
    double average;
};

int program(std::istream& cin, std::ostream& cout) {
    size_t n_students;
    cout << "Enter the amount of students: ";
    cin >> n_students;

    // Exits early if the inputted number of students is zero.
    if (n_students == 0) {
        cout << "Provide at least one input!\n";
        return 1;
    }

    std::vector<Student> students;
    cout << '\n';
    for (size_t i = 1; i <= n_students; i++) {
        Student student;
        cout << "[Data for Student #" << i << "]\n";

        // Gets the student ID (as a string)
        cout << "- ID: ";
        while (student.id.empty()) {
            std::getline(cin, student.id);
        }

        // Gets the midterm exam score
        while (true) {
            cout << "- Midterm exam score: ";
            cin >> student.midterm;

            // Loops again if the inputted score is invalid
            if (student.midterm > 100) {
                cout << "The score must not exceed 100!\n";
            }
            else {
                break;
            }
        }

        // Gets the final exam score
        while (true) {
            cout << "- Final exam score: ";
            cin >> student.final;

            // Loops again if the inputted score is invalid
            if (student.final > 100) {
                cout << "The score must not exceed 100!\n";
            }
            else {
                break;
            }
        }

        // Calculates the student average and pushes to the vector
        student.average = (student.midterm + student.final) / 2;
        students.push_back(student);
        cout << '\n';
    }

    // Final output
    cout << "[Calculated Average(s) of All " << n_students << " Student(s)]\n";
    double sum;
    for (Student& student : students) {
        cout << "- Student ID #" << student.id << ": " << student.average << '\n';
        sum += student.average; // Sums each of the students' average score
    }
    cout << "The overall average is " << (sum / n_students) << ".\n";

    return 0;
}
