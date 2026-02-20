#include <iostream>
#include <fstream>
#include "Student.h"
#include "AttendanceSession.h"

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_SESSIONS = 100;
Student students[MAX_STUDENTS];
AttendanceSession sessions[MAX_SESSIONS];

int studentCount = 0;
int sessionCount = 0;

// Function Prototypes
void addStudent();
void viewStudents();
void saveStudentsToFile();

void createSession();
void viewSessions();
void saveSessionsToFile();

int main() {
    int choice;

    do {
        cout << "\n=== DIGITAL ATTENDANCE SYSTEM ===\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Session\n";
        cout << "4. View Sessions\n";
        cout << "5. Exit\n";
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
            createSession();
            break;

        case 4:
            viewSessions();
            break;

        case 5:
            saveStudentsToFile();
            saveSessionsToFile();
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 5);

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

void createSession() {

    if (sessionCount >= MAX_SESSIONS) {
        std::cout << "Session limit reached.\n";
        return;
    }

    std::string courseCode, date, time;
    int duration;

    std::cin.ignore();

    std::cout << "Enter Course Code: ";
    getline(std::cin, courseCode);

    if (courseCode.empty()) {
        std::cout << "Course code cannot be empty.\n";
        return;
    }

    std::cout << "Enter Date (YYYY-MM-DD): ";
    getline(std::cin, date);

    std::cout << "Enter Start Time (HH:MM): ";
    getline(std::cin, time);

    std::cout << "Enter Duration (minutes): ";
    std::cin >> duration;

    if (std::cin.fail() || duration <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid duration.\n";
        return;
    }

    std::string sessionID = "S" + std::to_string(sessionCount + 1);

    sessions[sessionCount] =
        AttendanceSession(sessionID, courseCode, date, time, duration);

    sessionCount++;

    std::cout << "Session created successfully.\n";
}

void viewSessions() {

    if (sessionCount == 0) {
        std::cout << "No sessions created yet.\n";
        return;
    }

    for (int i = 0; i < sessionCount; i++) {
        sessions[i].display();
    }
}

void saveSessionsToFile() {

    std::ofstream file("sessions.txt");

    if (!file) {
        std::cout << "Error opening sessions file.\n";
        return;
    }

    for (int i = 0; i < sessionCount; i++) {
        file << sessions[i].toFileString() << std::endl;
    }

    file.close();
}