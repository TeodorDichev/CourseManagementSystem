/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "../Utills/MyString.h"
#include "../Utills/MyVector.hpp"
#include "Assignment.h"

class Course
{
private:
	MyString courseName;
	MyString coursePassword;
	MyVector<int> users;
	MyVector<Assignment> assignments;

public:
	Course();
	Course(const MyString& courseName, const MyString& coursePassword);

	bool isCoursePasswordCorrect(const MyString& password) const;
	bool hasUser(int id) const;

	const MyString& getCourseName() const;
	const MyString& getCoursePassword() const;
	const MyVector<Assignment>& getAssignments() const;
	const MyVector<int>& getUsersIds() const;
	int getUsersIdsSize() const;
	int getAssignmentsSize() const;

	void printSubmittedAssignments(const MyString& assignment) const;
	void printGradedAssignments(int studentId) const;
	void addUserToCourse(int userId);
	bool hasAssignmentWithName(const MyString& assignment) const;

	void gradeAssignment(const MyString& assignment, int studentId, float grade, const MyString& comment);
	void submitAssignment(const MyString& assignment, int studentId, const MyString& submission);
	void addAssignment(const Assignment& assignment);
};
