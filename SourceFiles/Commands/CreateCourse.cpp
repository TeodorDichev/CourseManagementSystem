#include "../../Headers/Commands/CreateCourse.h"

void CreateCourse::execute() const
{
	const User* user = userRepository->getLoggedUserConst();
	
	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isTutor())
	{
		throw std::invalid_argument("Only tutors can create courses!");
	}

	MyString courseName, coursePassword;
	std::cin >> courseName >> coursePassword;

	if (courseRepository->find(courseName))
	{
		throw std::invalid_argument("This course already exist!");
	}

	courseRepository->addCourse(Course(courseName, coursePassword));
	std::cout << "Course created successfully!" << std::endl;
}
