/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/Enroll.h"

void Enroll::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isStudent())
	{
		throw std::invalid_argument("Only students can enroll to courses!");
	}

	MyString courseName, coursePassword;
	std::cin >> courseName >> coursePassword;

	Course* course = courseRepository->find(courseName);

	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (!course->isCoursePasswordCorrect(coursePassword)) 
	{
		throw std::invalid_argument("Wrong password!");
	}
	if(course->hasUser(user->getId()))
	{
		throw std::invalid_argument("You are already in this course!");
	}

	course->addUserToCourse(user->getId());

	// Copy the assignments to the new student if there are any
	if (course->getAssignmentsSize() != 0)
	{
		MyVector<Assignment> assignments = course->getAssignments();
		int randomId = assignments[0].getAssignmentStudentId();

		for (int i = 0; i < assignments.size(); i++)
		{
			if (assignments[i].getAssignmentStudentId() == randomId)
			{
				course->addAssignment(Assignment(user->getId(), user->getFirstName(), user->getLastName(), courseName, assignments[i].getAssignmentName()));
			}
		}
	}

	std::cout << "You enrolled to the course successfully!" << std::endl;
}