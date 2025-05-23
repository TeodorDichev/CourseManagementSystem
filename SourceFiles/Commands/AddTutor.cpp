#include "../../Headers/Commands/AddTutor.h"

void AddTutor::execute() const
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

	userRepository->addUser(Tutor(firstName, lastName, password));
	std::cout << "Tutor added successfully!" << std::endl;
}