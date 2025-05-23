#include "../../Headers/Utills/SerializeFunctions.h"

static size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos, std::ios::beg);
	return size;
}

enum class Roles {
	ADMIN = 0,
	TUTOR = 1,
	STUDENT = 2
};

UserRepository* SerializeFunctions::userRepository = UserRepository::getInstance();
CourseRepository* SerializeFunctions::courseRepository = CourseRepository::getInstance();

void SerializeFunctions::loadSystemFromFile()
{	
	loadCoursesFromFile();
	loadUsersFromFile();
}

void SerializeFunctions::loadUsersFromFile()
{
	std::ifstream ifs("users.dat", std::ios::binary);
	if (!ifs.is_open())
	{
		// Create empty file
		std::ofstream ofs("users.dat", std::ios::binary);
		ofs.close();
		return;
	}
	if (getFileSize(ifs) == 0)
	{
		return;
	}

	while (true)
	{
		int id;
		ifs.read(reinterpret_cast<char*>(&id), sizeof(id));

		if (ifs.eof())
		{
			break;
		}

		MyString firstName = readStringFromFile(ifs);
		MyString lastName = readStringFromFile(ifs);
		MyString password = readStringFromFile(ifs);

		int roleInt;
		ifs.read(reinterpret_cast<char*>(&roleInt), sizeof(roleInt));
		Roles role = static_cast<Roles>(roleInt);

		User* user;
		switch (role)
		{
		case Roles::ADMIN:
			user = new Admin(firstName, lastName, password);
			break;
		case Roles::TUTOR:
			user = new Tutor(firstName, lastName, password);
			break;
		case Roles::STUDENT:
			user = new Student(firstName, lastName, password);
			break;
		default:
			throw std::invalid_argument("Invalid user Role!");
			break;
		}

		int messageCount = 0;
		ifs.read(reinterpret_cast<char*>(&messageCount), sizeof(messageCount));

		for (int i = 0; i < messageCount; ++i)
		{
			Message msg;
			loadMessageFromFile(msg, ifs);
			user->addMessageToUserInbox(msg);
		}

		userRepository->addUser(*user);
		delete user;
	}

	ifs.close();
}

void SerializeFunctions::loadCoursesFromFile()
{
	std::ifstream ifs("courses.dat", std::ios::binary);
	if (!ifs.is_open())
	{
		// Create empty file
		std::ofstream ofs("courses.dat", std::ios::binary);
		ofs.close();
		return;
	}
	if (getFileSize(ifs) == 0)
	{
		return;
	}

	while (true)
	{
		MyString courseName = readStringFromFile(ifs);

		if (ifs.eof())
		{
			break;
		}

		MyString coursePassword = readStringFromFile(ifs);

		Course c(courseName, coursePassword);

		int usersCount = 0;
		ifs.read(reinterpret_cast<char*>(&usersCount), sizeof(usersCount));

		for (int i = 0; i < usersCount; ++i)
		{
			int userId = 0;
			ifs.read(reinterpret_cast<char*>(&userId), sizeof(userId));
			c.addUserToCourse(userId);
		}


		int assignmentCount = 0;
		ifs.read(reinterpret_cast<char*>(&assignmentCount), sizeof(assignmentCount));

		for (int i = 0; i < assignmentCount; ++i)
		{
			Assignment a;
			loadAssignmentFromFile(a, ifs);
			c.addAssignment(a);
		}

		courseRepository->addCourse(c);
	}

	ifs.close();
}

void SerializeFunctions::loadMessageFromFile(Message& message, std::ifstream& ifs)
{
	int receiverId = message.getReceiverId();
	ifs.read(reinterpret_cast<char*>(&receiverId), sizeof(receiverId));

	MyString senderFirstName = readStringFromFile(ifs);
	MyString senderLastName = readStringFromFile(ifs);
	MyString sentOn = readStringFromFile(ifs);
	MyString content = readStringFromFile(ifs);

	message = Message(receiverId, senderFirstName, senderLastName, sentOn, content);
}

void SerializeFunctions::loadAssignmentFromFile(Assignment& assignment, std::ifstream& ifs)
{
	int studentId;
	ifs.read(reinterpret_cast<char*>(&studentId), sizeof(studentId));

	MyString courseName = readStringFromFile(ifs);
	MyString assignmentName = readStringFromFile(ifs);
	MyString studentFirstName = readStringFromFile(ifs);
	MyString studentLastName = readStringFromFile(ifs);

	assignment = Assignment(studentId, studentFirstName, studentLastName, courseName, assignmentName);

	bool isSubmitted;
	ifs.read(reinterpret_cast<char*>(&isSubmitted), sizeof(isSubmitted));

	if (isSubmitted)
	{
		MyString submission = readStringFromFile(ifs);
		assignment.addSubmission(submission);
	}

	bool isGraded;
	ifs.read(reinterpret_cast<char*>(&isGraded), sizeof(isGraded));

	if (isGraded)
	{
		float grade;
		ifs.read(reinterpret_cast<char*>(&grade), sizeof(grade));
		MyString comment = readStringFromFile(ifs);
		assignment.gradeAssignment(grade, comment);
	}
}

void SerializeFunctions::saveSystemToFile()
{
	courseRepository = CourseRepository::getInstance();
	userRepository = UserRepository::getInstance();
	
	saveUsersToFile();
	saveCoursesToFile();
}

void SerializeFunctions::saveUsersToFile()
{
	std::ofstream ofs("users.dat", std::ios::binary | std::ios::trunc);
	if (!ofs.is_open())
	{
		throw std::invalid_argument("Failed to open users.dat for writing.");
	}

	for (int i = 0; i < userRepository->users.getSize(); i++)
	{
		int id = userRepository->users[i]->getId();
		ofs.write(reinterpret_cast<const char*>(&id), sizeof(id));

		writeStringToFile(ofs, userRepository->users[i]->getFirstName());
		writeStringToFile(ofs, userRepository->users[i]->getLastName());
		writeStringToFile(ofs, userRepository->users[i]->getPassword());

		if (userRepository->users[i]->isAdmin())
		{
			int role = static_cast<int>(Roles::ADMIN);
			ofs.write(reinterpret_cast<const char*>(&role), sizeof(role));
		}
		else if (userRepository->users[i]->isTutor())
		{
			int role = static_cast<int>(Roles::TUTOR);
			ofs.write(reinterpret_cast<const char*>(&role), sizeof(role));
		}
		else if (userRepository->users[i]->isStudent())
		{
			int role = static_cast<int>(Roles::STUDENT);
			ofs.write(reinterpret_cast<const char*>(&role), sizeof(role));
		}

		const MyVector<Message> messages = userRepository->users[i]->getMessages();
		int size = messages.size();
		ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

		for (int i = 0; i < size; i++)
		{
			saveMessageToFile(messages[i], ofs);
		}
	}

	ofs.close();
}

void SerializeFunctions::saveCoursesToFile()
{
	std::ofstream ofs("courses.dat", std::ios::binary | std::ios::trunc);
	if (!ofs.is_open())
	{
		throw std::invalid_argument("Failed to open courses.dat for writing.");
	}

	for (int i = 0; i < courseRepository->courses.size(); i++)
	{
		writeStringToFile(ofs, courseRepository->courses[i].getCourseName());
		writeStringToFile(ofs, courseRepository->courses[i].getCoursePassword());

		const MyVector<int>& usersIds = courseRepository->courses[i].getUsersIds();
		int size = usersIds.size();
		ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

		for (int i = 0; i < usersIds.size(); i++)
		{
			ofs.write(reinterpret_cast<const char*>(&usersIds[i]), sizeof(int));
		}

		const MyVector<Assignment>& assignments = courseRepository->courses[i].getAssignments();
		size = assignments.size();
		ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

		for (int i = 0; i < assignments.size(); i++)
		{
			saveAssignmentsToFile(assignments[i], ofs);
		}
	}

	ofs.close();
}

void SerializeFunctions::saveMessageToFile(const Message& message, std::ofstream& ofs)
{
	int receiverId = message.getReceiverId();
	ofs.write(reinterpret_cast<const char*>(&receiverId), sizeof(receiverId));

	writeStringToFile(ofs, message.getSenderFirstName());
	writeStringToFile(ofs, message.getSenderLastName());
	writeStringToFile(ofs, message.getSentOn());
	writeStringToFile(ofs, message.getContent());
}

void SerializeFunctions::saveAssignmentsToFile(const Assignment& assignment, std::ofstream& ofs)
{
	int studentId = assignment.getAssignmentStudentId();
	ofs.write(reinterpret_cast<const char*>(&studentId), sizeof(studentId));

	writeStringToFile(ofs, assignment.getAssignmentCourseName());
	writeStringToFile(ofs, assignment.getAssignmentName());
	writeStringToFile(ofs, assignment.getStudentFirstName());
	writeStringToFile(ofs, assignment.getStudentLastName());

	bool isSubmitted = assignment.isSubmitted();
	ofs.write(reinterpret_cast<const char*>(&isSubmitted), sizeof(isSubmitted));
	if (isSubmitted)
	{
		writeStringToFile(ofs, assignment.getAssignmentSubmission());
	}

	bool isGraded = assignment.isGraded();
	ofs.write(reinterpret_cast<const char*>(&isGraded), sizeof(isGraded));
	if (isGraded)
	{
		float grade = assignment.getGrade();
		ofs.write(reinterpret_cast<const char*>(&grade), sizeof(grade));
		writeStringToFile(ofs, assignment.getAssignmentComment());
	}
}

void SerializeFunctions::writeStringToFile(std::ofstream& ofs, const MyString& str)
{
	int len = str.length();
	ofs.write((const char*)&len, sizeof(int));
	ofs.write(str.c_str(), sizeof(char) * len);
}

MyString SerializeFunctions::readStringFromFile(std::ifstream& ifs)
{
	int len = 0;
	ifs.read((char*)&len, sizeof(len));

	char* buff = new char[len + 1];
	ifs.read(buff, sizeof(char) * len);

	buff[len] = '\0';

	MyString toReturn(buff);

	delete[] buff;

	return toReturn;
}
