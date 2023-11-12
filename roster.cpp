#include "roster.h"
#include <iostream>
#include <string>
#include "student.h"

// Add()
void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (this->classRosterArray[i] == nullptr) {
            this->classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
            return;
        }
    }
    std::cout << "Error: Roster is full, cannot add more students." << std::endl;
}

// Remove()
void Roster::Remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getStudentID() == studentID) {
            delete this->classRosterArray[i];
            this->classRosterArray[i] = nullptr;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

Roster::Roster() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        classRosterArray[i] = nullptr;
    }
}

std::string Roster::GetStudentIDAt(int index) const
{
    return std::string();
}

Roster::~Roster() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}

// PrintAll()
void Roster::PrintAll() const {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (this->classRosterArray[i] != nullptr) {
            this->classRosterArray[i]->print();
        }
    }
}

// PrintAverageDaysInCourse()
void Roster::PrintAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getStudentID() == studentID) {
            int* days = this->classRosterArray[i]->getDaysToComplete();
            std::cout << "Average days in course for student ID " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3 << std::endl;
            return;
        }
    }
    std::cout << "Student ID not found." << std::endl;
}

// PrintInvalidEmails()
void Roster::PrintInvalidEmails() const {
    std::cout << "Invalid email addresses:" << std::endl;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (this->classRosterArray[i] != nullptr) {
            std::string email = this->classRosterArray[i]->getEmailAddress();
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << email << std::endl;
            }
        }
    }
}

// PrintByDegreeProgram()
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) const {
    std::cout << "Students in the " << degreeProgram << " program:" << std::endl;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->print();
        }
    }
}
