#include "roster.h"
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

int main() {
    // Print course title, the programming language used, student ID, and name
    std::cout << "Course Title: Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "WGU Student ID: 010642228" << std::endl;
    std::cout << "Student Name: Salman Omar" << std::endl;

    // Create an instance of the Roster class
    Roster classRoster;

    // Read and add students from file
    classRoster.readAndAddStudents("students.txt");

    // Other functionalities...
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();

    // Loop through classRosterArray, and for each element:
    for (int i = 0; i < Roster::MAX_STUDENTS; ++i) {
        std::string studentID = classRoster.GetStudentIDAt(i);
        if (!studentID.empty()) {
            classRoster.PrintAverageDaysInCourse(studentID);
        }
    }

    classRoster.PrintByDegreeProgram(SOFTWARE);
    classRoster.Remove("A3");
    classRoster.PrintAll();
    classRoster.Remove("A3"); // This should print a message that the student was not found.

    return 0;
}
