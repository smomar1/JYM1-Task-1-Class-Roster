#pragma once
#include <string>
#include "student.h"
#include <iostream>
#include "degree.h"

class Roster {
public:
	static const int MAX_STUDENTS = 5; // Maximum number of students

	// Constructor
	Roster();
	std::string GetStudentIDAt(int index) const;

	// Destructor
	~Roster();

	// Other methods
	void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void Remove(std::string StudentID);
	void PrintAll() const;
	void PrintAverageDaysInCourse(std::string studentID) const;
	void PrintInvalidEmails() const;
	void PrintByDegreeProgram(DegreeProgram degreeProgram) const;
	void readAndAddStudents(const std::string& filename);

private:
	Student* classRosterArray[MAX_STUDENTS]; // Array of student pointers
};
