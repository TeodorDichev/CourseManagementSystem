#pragma once
#include "Message.h"
#include "../Utills/MyVector.hpp"

class UserInbox
{
private:
	MyVector<Message> messages;
public:
	void addMessage(const Message& message);
	void clearInbox();
	void printUserInbox() const;

	const MyVector<Message>& getMessages() const;
};

