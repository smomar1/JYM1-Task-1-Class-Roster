#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

// Implementation of degreeProgramToString
std::string degreeProgramToString(DegreeProgram dp) {
    switch (dp) {
    case SECURITY: return "Security";
    case NETWORK: return "Network";
    case SOFTWARE: return "Software";
    default: return "Unknown";
    }
}

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}

// Default constructor
Student::Student() : Student("", "", "", "", 0, new int[3] {0, 0, 0}, DegreeProgram::SECURITY) {
}

// Destructor
Student::~Student() {
}

// Getters
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
int* Student::getDaysToComplete() const { return (int*)daysToComplete; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Setters
void Student::setStudentID(const std::string& studentID) { this->studentID = studentID; }
void Student::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Student::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Student::setEmailAddress(const std::string& emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToComplete(const int daysToComplete[]) {
    for (int i = 0; i < 3; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print()
void Student::print() const {
    std::cout << "Student ID: " << getStudentID() << "\t";
    std::cout << "First Name: " << getFirstName() << "\t";
    std::cout << "Last Name: " << getLastName() << "\t";
    std::cout << "Email Address: " << getEmailAddress() << "\t";
    std::cout << "Age: " << getAge() << "\t";
    std::cout << "daysInCourse: {" << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}";
    std::cout << "Degree Program: " << degreeProgramToString(getDegreeProgram()) << std::endl; 
}
