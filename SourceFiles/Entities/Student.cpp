/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Entities/Student.h"

Student::Student() : Student("", "", "")
{ 
	id = -1;
}

Student::Student(const MyString& firstName, const MyString& lastName, const MyString& password) : User(firstName, lastName, password)
{ }

User* Student::clone() const
{
	return new Student(*this);
}

void Student::printInfo() const
{
	std::cout << firstName << " " << lastName << " | " << "Student" << " | " << id << std::endl;
}

bool Student::isAdmin() const
{
	return false;
}

bool Student::isTutor() const
{
	return false;
}

bool Student::isStudent() const
{
	return true;
}
