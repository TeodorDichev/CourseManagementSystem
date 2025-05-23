/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../Headers/CourseManagementSystem.h"

void CourseManagementSystem::Run()
{
	SerializeFunctions::loadSystemFromFile();
	
	// Adding admin if this is the first running of the system
	UserRepository* userRepository = UserRepository::getInstance();
	if (!userRepository->find(0))
	{
		userRepository->addUser(Admin());
	}

	CommandFactory* factory = CommandFactory::getInstance();

	while (true) 
	{
		MyString input;
		std::cin >> input;

		if(input == "exit")
		{
			break;
		}

		try
		{
			Command* command = factory->readCommand(input);
			command->execute();
			delete command;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	SerializeFunctions::saveSystemToFile();

	UserRepository::freeInstance();
	CourseRepository::freeInstance();
	CommandFactory::freeInstance();
}
