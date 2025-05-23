/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/ViewAssignmentSubmissions.h"

void ViewAssignmentSubmissions::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isTutor())
	{
		throw std::invalid_argument("Only tutors can view assignment submissions!");
	}

	MyString courseName, assignmentName;
	std::cin >> courseName >> assignmentName;

	Course* course = courseRepository->find(courseName);
	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (!course->hasAssignmentWithName(assignmentName))
	{
		throw std::invalid_argument("Assignment does not exist!");
	}

	course->printSubmittedAssignments(assignmentName);
}