#pragma once
#include <string>
#include <iostream>
#include "degree.h"

class Student {
public:
	// Constructors
	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days[], DegreeProgram degreeProgram);

	// Destructors
	~Student();
	
	//Getters
	std::string getStudentID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmailAddress() const;
	int getAge() const;
	int* getDaysToComplete() const;
    DegreeProgram getDegreeProgram() const;

	//Setters
	void setStudentID(const std::string& studentID);
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
    void setEmailAddress(const std::string& emailAddress);
	void setAge(int age);
	void setDaysToComplete(const int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print() const;

private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;
};
