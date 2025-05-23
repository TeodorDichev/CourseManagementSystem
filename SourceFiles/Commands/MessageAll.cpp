/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/MessageAll.h"

void MessageAll::execute() const
{
	const User* sender = userRepository->getLoggedUserConst();
	if (!sender)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!sender->isAdmin())
	{
		throw std::invalid_argument("Only admins can message all!");
	}

	char buff[1024];
	std::cin.getline(buff, 1024);
	MyString contents = buff;

	userRepository->messageAll(contents);
	std::cout << "Message sent successfully!" << std::endl;
}