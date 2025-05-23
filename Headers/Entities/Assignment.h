#pragma once
#include "../../Headers/Utills/MyString.h"

class Assignment
{
private:
	int studentId;
	MyString studentFirstName;
	MyString studentLastName;
	MyString courseName;
	MyString assignmentName;
	MyString assignmentComment;
	MyString assignmentSubmission;
	bool submitted = false;
	float grade = 0;

public:
	Assignment();
	Assignment(int studentId, const MyString& studentFirstName, const MyString& studentLastName, const MyString& courseName, const MyString& assignmentName);

	int getAssignmentStudentId() const;
	const MyString& getStudentFirstName() const;
	const MyString& getStudentLastName() const;
	const MyString& getAssignmentCourseName() const;
	const MyString& getAssignmentName() const;
	const MyString& getAssignmentComment() const;
	const MyString& getAssignmentSubmission() const;
	float getGrade() const;

	void printAssignmentSubmission() const;
	void printAssignmentGrade() const;

	void addSubmission(const MyString& submission);
	void gradeAssignment(float grade, const MyString& comment);
	bool isGraded() const;
	bool isSubmitted() const;
};
