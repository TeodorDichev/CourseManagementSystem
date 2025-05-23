#include "../../Headers/Commands/MessageUser.h"

void MessageUser::execute() const
{
	const User* sender = userRepository->getLoggedUserConst();
	if (!sender)
	{
		throw std::invalid_argument("Log in first!");
	}	
	
	int id;
	std::cin >> id;

	char buff[1024];
	std::cin.getline(buff, 1024);
	MyString contents = buff;

	User* receiver = userRepository->find(id);
	if (!receiver)
	{
		throw std::invalid_argument("User does not exist!");
	}

	receiver->addMessageToUserInbox(Message(receiver->getId(), sender->getFirstName(), sender->getLastName(), contents));
	std::cout << "Message sent successfully!" << std::endl;
}