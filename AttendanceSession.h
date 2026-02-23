#ifndef ATTENDANCESESSION_H
#define ATTENDANCESESSION_H

#include "Student.h"
#include <string>
#include <ostream>

class AttendanceSession {
private:
    std::string sessionID;
    std::string courseCode;
    std::string date;
    std::string startTime;
    std::string attendanceStatus[100];
    std::string getAttendanceStatus(int index) const;
    int totalStudents;
    int durationMinutes;

public:
    AttendanceSession();
    AttendanceSession(std::string id, std::string code,
                      std::string date, std::string time,
                      int duration);

    // Getters
    std::string getSessionID() const;
    std::string getCourseCode() const;
    std::string getDate() const;
    std::string getStartTime() const;
    int getDuration() const;

    // Display
    void display() const;
    void markAttendance(const Student students[], int studentCount);
    void displayAttendance(const Student students[], int studentCount) const;
    void displaySummary(int studentCount) const;
    void loadAttendanceStatus(int index, std::string status);
    void saveAttendanceToFile(std::ostream& file, int studentCount) const;

    // File format
    std::string toFileString() const;
};

#endif