/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/GetMailBox.h"

void GetMailBox::execute() const
{
	User* user = userRepository->getLoggedUser();
	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	
	user->printUserInbox();
}
