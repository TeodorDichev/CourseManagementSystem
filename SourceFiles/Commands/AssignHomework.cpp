/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/AssignHomework.h"

void AssignHomework::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isTutor())
	{
		throw std::invalid_argument("Only tutors can assign homework to students");
	}

	MyString courseName, assignmentName;
	std::cin >> courseName >> assignmentName;

	Course* course = courseRepository->find(courseName);
	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (!course->hasUser(user->getId()))
	{
		throw std::invalid_argument("You must be added to the course before you can assign homework!");
	}
	if (course->hasAssignmentWithName(assignmentName))
	{
		throw std::invalid_argument("Assignment already exists!");
	}

	const MyVector<int>& usersIds = course->getUsersIds();
	for (int i = 0; i < usersIds.size(); i++)
	{
		const User* student = userRepository->find(usersIds[i]);

		if (!student)
		{
			throw std::invalid_argument("Tried to assign homework to invalid user!");
		}

		if (student->isStudent())
		{
			course->addAssignment(Assignment(student->getId(), student->getFirstName(), student->getLastName(), courseName, assignmentName));
		}
	}

	std::cout << "Homework assigned successfully!" << std::endl;
}