#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function Prototypes
void addStudent();
void viewStudents();
void saveStudentsToFile();

int main() {
    int choice;

    do {
        cout << "\n=== DIGITAL ATTENDANCE SYSTEM ===\n";
        cout << "1. Register Student\n";
        cout << "2. View All Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            saveStudentsToFile();
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 3);

    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student limit reached.\n";
        return;
    }

    string index, name, programme;

    cin.ignore(); // clear 

    cout << "Enter Index Number: ";
    getline(cin, index);

    if (index.empty()) {
        cout << "Index number cannot be empty.\n";
        return;
    }

    cout << "Enter Full Name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    cout << "Enter Programme: ";
    getline(cin, programme);

    students[studentCount] = Student(index, name, programme);
    studentCount++;

    cout << "Student registered successfully.\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No students registered yet.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        students[i].display();
    }
}

void saveStudentsToFile() {
    ofstream file("students.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        file << students[i].toFileString() << endl;
    }

    file.close();
}
