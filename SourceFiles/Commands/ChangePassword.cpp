/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/ChangePassword.h"

void ChangePassword::execute() const
{
	MyString oldPassword, newPassword;
	std::cin >> oldPassword >> newPassword;

	User* user = userRepository->getLoggedUser();
	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isUserPasswordCorrect(oldPassword)) 
	{
		throw std::invalid_argument("Wrong password!");
	}

	user->setNewPassword(newPassword);
	std::cout << "Password changed successfully!" << std::endl;
}
