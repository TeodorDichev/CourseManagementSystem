/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/GradeAssignment.h"

void GradeAssignment::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isTutor())
	{
		throw std::invalid_argument("Only tutors can grade assignments!");
	}

	MyString courseName, assignmentName;
	int id;
	float grade;
	std::cin >> courseName >> assignmentName >> id >> grade;

	char buff[1024];
	std::cin.getline(buff, 1024);
	MyString comment = buff;

	Course* course = courseRepository->find(courseName);
	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (!course->hasAssignmentWithName(assignmentName))
	{
		throw std::invalid_argument("Assignment does not exist!");
	}
	if (!course->hasUser(id))
	{
		throw std::invalid_argument("The student is not part of this course!");
	}
	
	course->gradeAssignment(assignmentName, id, grade, comment);
	std::cout << "Assignment graded successfully!" << std::endl;
}