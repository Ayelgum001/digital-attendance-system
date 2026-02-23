#include "AttendanceSession.h"
#include <iostream>
#include <sstream>

AttendanceSession::AttendanceSession() {
    sessionID = "";
    courseCode = "";
    date = "";
    startTime = "";
    durationMinutes = 0;
}

AttendanceSession::AttendanceSession(std::string id,
                                     std::string code,
                                     std::string d,
                                     std::string time,
                                     int duration) {
    sessionID = id;
    courseCode = code;
    date = d;
    startTime = time;
    durationMinutes = duration;
}

std::string AttendanceSession::getSessionID() const {
    return sessionID;
}

std::string AttendanceSession::getCourseCode() const {
    return courseCode;
}

std::string AttendanceSession::getDate() const {
    return date;
}

std::string AttendanceSession::getStartTime() const {
    return startTime;
}

int AttendanceSession::getDuration() const {
    return durationMinutes;
}

void AttendanceSession::display() const {
    std::cout << "Session ID: " << sessionID << std::endl;
    std::cout << "Course Code: " << courseCode << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Start Time: " << startTime << std::endl;
    std::cout << "Duration: " << durationMinutes << " minutes\n";
    std::cout << "----------------------------\n";
}

std::string AttendanceSession::toFileString() const {
    std::stringstream ss;
    ss << sessionID << ","
       << courseCode << ","
       << date << ","
       << startTime << ","
       << durationMinutes;
    return ss.str();
}
void AttendanceSession::markAttendance(const Student students[], int studentCount) {

    if (studentCount == 0) {
        std::cout << "No students registered.\n";
        return;
    }

    totalStudents = studentCount;

    for (int i = 0; i < studentCount; i++) {
        std::cout << "\nStudent: " << students[i].getFullName() << std::endl;
        std::cout << "1. Present\n";
        std::cout << "2. Absent\n";
        std::cout << "3. Late\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Marked as Absent by default.\n";
            attendanceStatus[i] = "Absent";
        } else {
            switch (choice) {
                case 1: attendanceStatus[i] = "Present"; break;
                case 2: attendanceStatus[i] = "Absent"; break;
                case 3: attendanceStatus[i] = "Late"; break;
            }
        }
    }

    std::cout << "\nAttendance recorded successfully.\n";
}

void AttendanceSession::displayAttendance(const Student students[], int studentCount) const {

    if (studentCount == 0) {
        std::cout << "No students available.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        std::cout << students[i].getFullName()
                  << " - "
                  << attendanceStatus[i]
                  << std::endl;
    }
}

void AttendanceSession::displaySummary(int studentCount) const {

    int present = 0, absent = 0, late = 0;

    for (int i = 0; i < studentCount; i++) {
        if (attendanceStatus[i] == "Present") present++;
        else if (attendanceStatus[i] == "Absent") absent++;
        else if (attendanceStatus[i] == "Late") late++;
    }

    std::cout << "\nAttendance Summary:\n";
    std::cout << "Present: " << present << std::endl;
    std::cout << "Absent : " << absent << std::endl;
    std::cout << "Late   : " << late << std::endl;
}