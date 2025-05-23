/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "../Repositories/UserRepository.h"
#include "../Repositories/CourseRepository.h"
#include<fstream>

class SerializeFunctions
{
public:
	static void saveSystemToFile();
	static void loadSystemFromFile();

private:
	static UserRepository* userRepository;
	static CourseRepository* courseRepository;

	static void loadUsersFromFile();
	static void loadCoursesFromFile();
	static void loadMessageFromFile(Message& message, std::ifstream& ifs);
	static void loadAssignmentFromFile(Assignment& assignment, std::ifstream& ifs);

	static void saveUsersToFile();
	static void saveCoursesToFile();
	static void saveMessageToFile(const Message& message, std::ofstream& ofs);
	static void saveAssignmentsToFile(const Assignment& assignment, std::ofstream& ofs);

	static void writeStringToFile(std::ofstream& ofs, const MyString& str);
	static MyString readStringFromFile(std::ifstream& ifs);
};
