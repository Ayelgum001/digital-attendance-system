#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string indexNumber;
    std::string fullName;
    std::string programme;

public:
    // Constructors
    Student();
    Student(std::string idx, std::string name, std::string prog);

    // Getters
    std::string getIndexNumber() const;
    std::string getFullName() const;
    std::string getProgramme() const;

    // Display student details
    void display() const;

    // Convert student to file format
    std::string toFileString() const;
};

#endif
