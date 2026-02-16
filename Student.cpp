#include "Student.h"
#include <iostream>
#include <sstream>

// Default constructor
Student::Student() {
    indexNumber = "";
    fullName = "";
    programme = "";
}

// Parameterized constructor
Student::Student(std::string idx, std::string name, std::string prog) {
    indexNumber = idx;
    fullName = name;
    programme = prog;
}

// Getters
std::string Student::getIndexNumber() const {
    return indexNumber;
}

std::string Student::getFullName() const {
    return fullName;
}

std::string Student::getProgramme() const {
    return programme;
}

// Display function
void Student::display() const {
    std::cout << "Index Number: " << indexNumber << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Programme: " << programme << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

// Format for file storage
std::string Student::toFileString() const {
    std::stringstream ss;
    ss << indexNumber << "," << fullName << "," << programme;
    return ss.str();
}
