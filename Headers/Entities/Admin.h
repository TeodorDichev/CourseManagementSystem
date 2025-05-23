/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Tutor.h"
#include "Student.h"

class Admin : public User
{
public:
	Admin();
	Admin(const MyString& firstName, const MyString& lastName, const MyString& password);

	User* clone() const override;

	void printInfo() const override;

	bool isAdmin() const override;
	bool isTutor() const override;
	bool isStudent() const override;
};
