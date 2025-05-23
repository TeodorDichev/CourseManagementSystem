/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Entities/User.h"

int User::currIdIndex = 0;

User::User()
{ 
	id = -1;
}

User::User(const MyString& firstName, const MyString& lastName, const MyString& password) :firstName(firstName), lastName(lastName), password(password)
{ 
	id = currIdIndex++;
}

bool User::isUserPasswordCorrect(const MyString& password) const
{
	return this->password == password;
}

const MyString& User::getFirstName() const
{
	return firstName;
}

const MyString& User::getPassword() const
{
	return password;
}

const MyString& User::getLastName() const
{
	return lastName;
}

const MyVector<Message>& User::getMessages() const
{
	return inbox.getMessages();
}

int User::getId() const
{
	return id;
}

void User::printUserInbox() const
{
	inbox.printUserInbox();
}

void User::setNewPassword(const MyString& password)
{
	this->password = password;
}

void User::addMessageToUserInbox(const Message& message)
{
	inbox.addMessage(message);
}

void User::clearUserInbox()
{
	inbox.clearInbox();
}
