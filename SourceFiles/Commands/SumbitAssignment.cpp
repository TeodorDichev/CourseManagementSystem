#include "../../Headers/Commands/SubmitAssignment.h"

void SubmitAssignment::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isStudent())
	{
		throw std::invalid_argument("Only students can submit assignments!");
	}

	MyString courseName, assignmentName;
	std::cin >> courseName >> assignmentName;

	char buff[1024];
	std::cin.getline(buff, 1024);
	MyString contents = buff;

	Course* course = courseRepository->find(courseName);
	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (!course->hasAssignmentWithName(assignmentName))
	{
		throw std::invalid_argument("Assignment does not exist!");
	}

	course->submitAssignment(assignmentName, user->getId(), contents);
	std::cout << "Assignment was submitted successfully!" << std::endl;
}