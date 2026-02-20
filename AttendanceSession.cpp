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