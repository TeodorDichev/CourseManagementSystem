#pragma once
#include "User.h"
#include "Course.h"

class Tutor : public User
{
public:
	Tutor();
	Tutor(const MyString& firstName, const MyString& lastName, const MyString& password);

	User* clone() const override;

	void printInfo() const override;

	bool isAdmin() const override;
	bool isTutor() const override;
	bool isStudent() const override;
};
