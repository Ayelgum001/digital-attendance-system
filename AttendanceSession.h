#ifndef ATTENDANCESESSION_H
#define ATTENDANCESESSION_H

#include <string>

class AttendanceSession {
private:
    std::string sessionID;
    std::string courseCode;
    std::string date;
    std::string startTime;
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

    // File format
    std::string toFileString() const;
};

#endif