/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "../Entities/Admin.h"
#include "../Entities/Student.h"
#include "../Entities/Tutor.h"
#include "../Utills/HeterogeneousContainer.hpp"

class UserRepository
{
private:
	UserRepository();

	static UserRepository* instance;
	int loggedUserId;

	HeterogeneousContainer<User> users;

public:
	static UserRepository* getInstance();
	static void freeInstance();

	User* find(int id);

	const User* getLoggedUserConst() const;
	User* getLoggedUser();

	void logUser(int id, const MyString& password);
	void logOutUser();

	void addUser(const User& user);

	void messageAll(const MyString& content);

	friend class SerializeFunctions;
};
