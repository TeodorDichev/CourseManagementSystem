/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Entities/Course.h"

bool Course::isCoursePasswordCorrect(const MyString& password) const
{
	return coursePassword == password;
}

bool Course::hasUser(int id) const
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i] == id)
		{
			return true;
		}
	}

	return false;
}

Course::Course() : Course("", "")
{ }

Course::Course(const MyString& courseName, const MyString& coursePassword) : courseName(courseName), coursePassword(coursePassword)
{ }

const MyString& Course::getCourseName() const
{
	return courseName;
}

const MyString& Course::getCoursePassword() const
{
	return coursePassword;
}

const MyVector<Assignment>& Course::getAssignments() const
{
	return assignments;
}

const MyVector<int>& Course::getUsersIds() const
{
	return users;
}

int Course::getUsersIdsSize() const
{
	return users.size();
}

int Course::getAssignmentsSize() const
{
	return assignments.size();
}

void Course::printGradedAssignments(int studentId) const
{
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignments[i].isGraded() && assignments[i].getAssignmentStudentId() == studentId)
		{
			assignments[i].printAssignmentGrade();
		}
	}
}

void Course::printSubmittedAssignments(const MyString& assignment) const
{
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignments[i].getAssignmentName() == assignment && assignments[i].isSubmitted())
		{
			assignments[i].printAssignmentSubmission();
		}
	}

	if (assignments.size() == 0)
	{
		std::cout << "There have not been any submissions, yet." << std::endl;
	}
}

void Course::addUserToCourse(int userId)
{
	users.push_back(userId);
}

bool Course::hasAssignmentWithName(const MyString& assignment) const
{
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignments[i].getAssignmentName() == assignment)
		{
			return true;
		}
	}

	return false;
}

void Course::gradeAssignment(const MyString& assignment, int studentId, float grade, const MyString& comment)
{
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignments[i].getAssignmentName() == assignment && assignments[i].getAssignmentStudentId() == studentId)
		{
			if (assignments[i].isGraded())
			{
				throw std::invalid_argument("Assignment is already graded!");
			}

			assignments[i].gradeAssignment(grade, comment);
			return;
		}
	}
}

void Course::submitAssignment(const MyString& assignment, int studentId, const MyString& submission)
{
	for (int i = 0; i < assignments.size(); i++)
	{
		if (assignments[i].getAssignmentName() == assignment && assignments[i].getAssignmentStudentId() == studentId)
		{
			if (assignments[i].isSubmitted())
			{
				throw std::invalid_argument("Assignment is already submitted!");
			}

			assignments[i].addSubmission(submission);
			return;
		}
	}
}

void Course::addAssignment(const Assignment& assignment)
{
	assignments.push_back(assignment);
}
