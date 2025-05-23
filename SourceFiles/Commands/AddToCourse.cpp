#include "../../Headers/Commands/AddToCourse.h"

void AddToCourse::execute() const
{
	const User* loggedUser = userRepository->getLoggedUserConst();

	if (!loggedUser)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!loggedUser->isTutor())
	{
		throw std::invalid_argument("Only tutors can add to courses!");
	}

	MyString courseName;
	int id;
	std::cin >> courseName >> id;

	Course * course = courseRepository->find(courseName);

	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (course->hasUser(id))
	{
		throw std::invalid_argument("User is already added to this course!");
	}

	const User* user = userRepository->find(id);
	if (!user)
	{
		throw std::invalid_argument("User with this id does not exist!");
	}
	if (user->isAdmin())
	{
		throw std::invalid_argument("Admins cannot be added to courses!");
	}

	course->addUserToCourse(id);
	if (user->isStudent() && course->getAssignmentsSize() != 0)
	{
		// Copy the assignments to the new student if there are any
		MyVector<Assignment> assignments = course->getAssignments();
		int randomId = assignments[0].getAssignmentStudentId();

		for (int i = 0; i < assignments.size(); i++)
		{
			if (assignments[i].getAssignmentStudentId() == randomId)
			{
				course->addAssignment(Assignment(id, user->getFirstName(), user->getLastName(), courseName, assignments[i].getAssignmentName()));
			}
		}
	}

	std::cout << "User was added to the course successfully!" << std::endl;
}
