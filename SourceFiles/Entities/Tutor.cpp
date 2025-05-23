#include "../../Headers/Entities/Tutor.h"

Tutor::Tutor() : Tutor("", "", "")
{ 
	id = -1;
}

Tutor::Tutor(const MyString& firstName, const MyString& lastName, const MyString& password) : User(firstName, lastName, password)
{ }

User* Tutor::clone() const
{
	return new Tutor(*this);
}

void Tutor::printInfo() const
{
	std::cout << firstName << " " << lastName << " | " << "Tutor" << " | " << id << std::endl;
}

bool Tutor::isAdmin() const
{
	return false;
}

bool Tutor::isTutor() const
{
	return true;
}

bool Tutor::isStudent() const
{
	return false;
}
