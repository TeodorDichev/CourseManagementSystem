#include "../../Headers/Entities/UserInbox.h"

void UserInbox::addMessage(const Message& message)
{
	messages.push_back(message);
}

void UserInbox::clearInbox()
{
	messages.clear();
}

void UserInbox::printUserInbox() const
{
	for (int i = 0; i < messages.size(); ++i) 
	{
		messages[i].printMessage();
	}
	if (messages.size() == 0) 
	{
		std::cout << "You have no messages!" << std::endl;
	}
}

const MyVector<Message>& UserInbox::getMessages() const
{
	return messages;
}
