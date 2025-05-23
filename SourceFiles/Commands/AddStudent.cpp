#include "../../Headers/Commands/AddStudent.h"

void AddStudent::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isAdmin())
	{
		throw std::invalid_argument("Only admins can add students");
	}
	MyString firstName, lastName, password;
	std::cin >> firstName >> lastName >> password;

	userRepository->addUser(Student(firstName, lastName, password));
	std::cout << "Student added successfully!" << std::endl;
}
