#include "../../preamble.h"


struct Student {
    uint64_t nisn;
    std::string name;
    double value;
};

std::vector<Student> student_list = { // Provided student list
    {9960312699, "Handi Ramadhan", 90},
    {9963959682, "Rio Alfandra", 55},
    {9950310962, "Ronaldo Valentino Uneputty", 80},
    {9970272750, "Achmad Yaumil Fadjri R.", 60},
    {9970293945, "Alivia Rahma Pramesti", 70},
    {9952382180, "Ari Lutfianto", 65},
    {9965653989, "Arief Budiman", 60}};

template <typename T>
void insertionSort(std::vector<Student>& list, std::function<T(Student&)> key) {
    // Sort by descending order
    for (size_t i = 1; i < list.size(); i++) {
        Student current = list[i];

        // Iterates backwards through the preceding elements
        int64_t j = i - 1;
        while (j >= 0 && key(list[j]) < key(current)) {
            // Shifts preceding elements that are higher in value forwards
            list[j + 1] = list[j];
            j--;
        }

        // Inserts the current element back in order
        list[j + 1] = current;
    }
}

template <typename T>
void selectionSort(std::vector<Student>& list, std::function<T(Student&)> key) {
    // Sort by descending order
    for (size_t i = 0; i < list.size() - 1; i++) {
        // Finds the maximum over the elements following `i`
        size_t max_i = i;
        for (size_t j = i + 1; j < list.size(); j++) {
            if (key(list[j]) > key(list[max_i])) {
                max_i = j;
            }
        }

        // Swaps if there's a value higher than `i`
        if (max_i != i) {
            std::swap(list[i], list[max_i]);
        }
    }
}

template <typename T> void bubbleSort(std::vector<Student>& list, std::function<T(Student&)> key) {
    // Sort by descending order
    for (size_t i = 0; i < list.size() - 1; i++) {
        // Iterates over elements preceding `i`
        for (size_t j = 0; j < list.size() - i - 1; j++) {
            // Swaps elements that are in the incorrect order
            if (key(list[j]) < key(list[j + 1])) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

int64_t binarySearch(const std::vector<Student>& list, uint64_t nisn) {
    size_t left = 0;
    size_t right = list.size() - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;

        // The target NISN is found in the middle.
        if (list[mid].nisn == nisn) {
            return mid;
        }
        // The target NISN is in the left half.
        else if (list[mid].nisn < nisn) {
            right = mid - 1;
        }
        // The target NISN is in the right half.
        else {
            left = mid + 1;
        }
    }

    // The target NISN is not found.
    return -1;
}

void printStudents(const std::vector<Student>& students, std::ostream& cout) {
    for (size_t i = 0; i < students.size(); i++) {
        Student student = students[i];
        cout << (i + 1) << ". " << student.name << " (" << student.nisn << "): " << student.value
             << '\n';
    }
}

int program(std::istream& cin, std::ostream& cout) {
    cout << "[List of Students]\n";
    printStudents(student_list, cout);

    cout << "\n[Sorted Descending by NISN using Insertion Sort]\n";
    std::vector<Student> insertion_nisn = student_list;
    insertionSort<uint32_t>(insertion_nisn, [](Student& student) { return student.nisn; });
    printStudents(insertion_nisn, cout);

    cout << "\n[Sorted Descending by Value using Insertion Sort]\n";
    std::vector<Student> insertion_value = student_list;
    insertionSort<double>(insertion_value, [](Student& student) { return student.value; });
    printStudents(insertion_value, cout);

    cout << "\n[Sorted Descending by NISN using Selection Sort]\n";
    std::vector<Student> selection_nisn = student_list;
    selectionSort<uint32_t>(selection_nisn, [](Student& student) { return student.nisn; });
    printStudents(selection_nisn, cout);

    cout << "\n[Sorted Descending by Value using Selection Sort]\n";
    std::vector<Student> selection_value = student_list;
    selectionSort<double>(selection_value, [](Student& student) { return student.value; });
    printStudents(selection_value, cout);

    cout << "\n[Sorted Descending by NISN using Bubble Sort]\n";
    std::vector<Student> bubble_nisn = student_list;
    bubbleSort<uint32_t>(bubble_nisn, [](Student& student) { return student.nisn; });
    printStudents(bubble_nisn, cout);

    cout << "\n[Sorted Descending by Value using Bubble Sort]\n";
    std::vector<Student> bubble_value = student_list;
    bubbleSort<double>(bubble_value, [](Student& student) { return student.value; });
    printStudents(bubble_value, cout);

    uint64_t searched_nisn = 9950310962;
    cout << "\n[Searching for " << searched_nisn << "]\n";
    int64_t index = binarySearch(insertion_nisn, searched_nisn);
    if (index == -1) {
        cout << "Not found.\n";
    }
    else {
        printStudents({insertion_nisn[index]}, cout);
    }

    cout << "\n[Change the Names of Students with 60 to \"Joko\"]\n";
    std::vector<Student> jokofied = student_list;
    // Does linear/sequential search over each element for students with 60
    for (Student& student : jokofied) {
        if (student.value == 60) {
            student.name = "Joko";
        }
    }
    printStudents(jokofied, cout);

    return 0;
}
