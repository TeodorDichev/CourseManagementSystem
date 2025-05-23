#include "../../Headers/Commands/Login.h"

void Login::execute() const
{
	int id;
	MyString password;
	std::cin >> id >> password;

	if (userRepository->getLoggedUserConst())
	{
		throw std::invalid_argument("Log out first!");
	}

	userRepository->logUser(id, password);
}
