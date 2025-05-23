#include "../../Headers/Commands/ClearMailBox.h"

void ClearMailBox::execute() const
{
	User* user = userRepository->getLoggedUser();
	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	user->clearUserInbox();
	std::cout << "MailBox cleared successfully!" << std::endl;
}
