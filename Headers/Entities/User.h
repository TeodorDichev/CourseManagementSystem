#pragma once
#include "../Utills/MyString.h"
#include "../Utills/MyVector.hpp"
#include "UserInbox.h"
#include "Message.h"

class User
{
protected:
	static int currIdIndex;

	int id;
	MyString firstName;
	MyString lastName;
	MyString password;
	UserInbox inbox;

public:
	User();
	User(const MyString& firstName, const MyString& lastName, const MyString& password);
	virtual ~User() = default;

	virtual User* clone() const = 0;

	bool isUserPasswordCorrect(const MyString& password) const;
	const MyString& getPassword() const;
	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyVector<Message>& getMessages() const;
	int getId() const;
	void printUserInbox() const;

	void setNewPassword(const MyString& password);
	void addMessageToUserInbox(const Message& message);
	void clearUserInbox();

	virtual bool isAdmin() const = 0;
	virtual bool isTutor() const = 0;
	virtual bool isStudent() const = 0;

	virtual void printInfo() const = 0;
};
