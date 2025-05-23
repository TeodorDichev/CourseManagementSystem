/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Entities/Assignment.h"

Assignment::Assignment() : Assignment(-1, "", "", "", "")
{ }

Assignment::Assignment(int studentId, const MyString& studentFirstName, const MyString& studentLastName, const MyString& courseName, const MyString& assignmentName)
	: studentId(studentId), studentFirstName(studentFirstName), studentLastName(studentLastName), courseName(courseName), assignmentName(assignmentName)
{ }

int Assignment::getAssignmentStudentId() const
{
	return studentId;
}

const MyString& Assignment::getStudentFirstName() const
{
	return studentFirstName;
}

const MyString& Assignment::getStudentLastName() const
{
	return studentLastName;
}

const MyString& Assignment::getAssignmentName() const
{
	return assignmentName;
}

const MyString& Assignment::getAssignmentComment() const
{
	return assignmentComment;
}

const MyString& Assignment::getAssignmentSubmission() const
{
	return assignmentSubmission;
}

const MyString& Assignment::getAssignmentCourseName() const
{
	return courseName;
}

float Assignment::getGrade() const
{
	return this->grade;
}

void Assignment::addSubmission(const MyString& submission)
{
	submitted = true;
	assignmentSubmission = submission;
}

void Assignment::gradeAssignment(float grade, const MyString& comment)
{
	this->grade = grade;
	this->assignmentComment = comment;
}

bool Assignment::isGraded() const
{
	return grade != 0;
}

bool Assignment::isSubmitted() const
{
	return submitted;
}

void Assignment::printAssignmentSubmission() const 
{
	std::cout << studentFirstName << " " << studentLastName << ", " << studentId << ": " << assignmentSubmission << std::endl;
}

void Assignment::printAssignmentGrade() const 
{
	std::cout << courseName << " | " << assignmentName << " | " << grade << " | " << assignmentComment << std::endl;
}