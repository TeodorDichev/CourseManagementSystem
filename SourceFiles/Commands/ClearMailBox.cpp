/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

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
