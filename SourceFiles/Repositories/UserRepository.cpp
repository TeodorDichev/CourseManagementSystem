/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Repositories/UserRepository.h"

UserRepository::UserRepository() : loggedUserId(-1) 
{ }

UserRepository* UserRepository::instance = nullptr;

UserRepository* UserRepository::getInstance()
{
	if (!instance)
	{
		instance = new UserRepository();
	}

	return instance;
}

void UserRepository::freeInstance()
{
	delete instance;
	instance = nullptr;
}

User* UserRepository::find(int id)
{
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i]->getId() == id)
		{
			return users[i];
		}
	}
	
	return nullptr;
}

const User* UserRepository::getLoggedUserConst() const
{
	if (loggedUserId < 0)
	{
		return nullptr;
	}

	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i]->getId() == loggedUserId)
		{
			return users[i];
		}
	}

}

User* UserRepository::getLoggedUser()
{
	return find(loggedUserId);
}

void UserRepository::logUser(int id, const MyString& password)
{
	User* user = find(id);

	if (!user)
	{
		return;
	}
	if (user->isUserPasswordCorrect(password))
	{
		loggedUserId = id;
	}

	user->printInfo();
}

void UserRepository::logOutUser()
{
	loggedUserId = -1;
}

void UserRepository::addUser(const User& user)
{
	users.addObject(user);
}

void UserRepository::messageAll(const MyString& content) 
{
	User* admin = find(0);
	
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i]->getId() == 0)
		{
			continue;
		}

		users[i]->addMessageToUserInbox(Message(users[i]->getId(), admin->getFirstName(), admin->getLastName(), content));
	}
}
