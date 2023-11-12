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

    // Add each student to classRoster
    // Placeholder for student data addition - the actual data should be added here
    // classRoster.Add("A1", "John", "Doe", "johndoe@email.com", 20, 30, 35, 40, SOFTWARE);
    classRoster.Add("A1", "John", "Smith", "John1989@gmail.com", 20, 30, 35, 40, SECURITY);
    classRoster.Add("A2", "Suzan", "Erickson", "Erickson_1990@gmail.com", 19, 50, 30, 40, NETWORK);
    classRoster.Add("A3", "Jack", "Napoli", "The_lawyer99@yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.Add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.Add("A5", "Salman", "Omar", "somar27@wgu.edu", 24, 15, 30, 45, SOFTWARE);

    // Demonstrate other functionalities
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();

    // Loop through classRosterArray, and for each element:
    // Note: This loop is a placeholder. The actual student IDs should be retrieved from the classRosterArray.
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
