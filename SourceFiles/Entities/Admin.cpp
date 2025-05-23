/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Entities/Admin.h"

Admin::Admin() : Admin("admin", "", "0000")
{ 
	id = 0;
}

Admin::Admin(const MyString& firstName, const MyString& lastName, const MyString& password) : User(firstName, lastName, password)
{ 
	id = 0;
}

User* Admin::clone() const
{
	return new Admin(*this);
}

void Admin::printInfo() const
{
	std::cout << firstName << " " << lastName << " | " << "Admin" << " | " << id << std::endl;
}

bool Admin::isAdmin() const
{
	return true;
}

bool Admin::isTutor() const
{
	return false;
}

bool Admin::isStudent() const
{
	return false;
}
