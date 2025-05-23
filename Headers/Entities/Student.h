/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "User.h"
#include "Course.h"

class Student : public User
{
public:
	Student();
	Student(const MyString& firstName, const MyString& lastName, const MyString& password);

	User* clone() const override;

	void printInfo() const override;

	bool isAdmin() const override;
	bool isTutor() const override;
	bool isStudent() const override;
};
