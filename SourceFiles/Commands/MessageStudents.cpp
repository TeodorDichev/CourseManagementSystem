#include "../../Headers/Commands/MessageStudents.h"

void MessageStudents::execute() const
{
	const User* sender = userRepository->getLoggedUserConst();
	if (!sender)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!sender->isTutor())
	{
		throw std::invalid_argument("Only tutors can message all students!");
	}

	MyString courseName;
	std::cin >> courseName;

	char buff[1024];
	std::cin.getline(buff, 1024);
	MyString contents = buff;

	Course* course = courseRepository->find(courseName);
	if (!course)
	{
		throw std::invalid_argument("Course does not exist!");
	}
	if (!course->hasUser(sender->getId()))
	{
		throw std::invalid_argument("You must be added to the course before you can send messages!");
	}

	const MyVector<int>& usersIds = course->getUsersIds();
	for (int i = 0; i < usersIds.size(); i++)
	{
		User* student = userRepository->find(usersIds[i]);

		if (!student)
		{
			throw std::invalid_argument("Tried to sent message to invalid user!");
		}
		if (student->isStudent())
		{
			student->addMessageToUserInbox(Message(student->getId(), sender->getFirstName(), sender->getLastName(), contents));
		}
	}
	std::cout << "Message sent successfully!" << std::endl;
}