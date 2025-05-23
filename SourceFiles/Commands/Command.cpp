#include "../../Headers/Commands/Command.h"

Command::Command()
{
	userRepository = UserRepository::getInstance();
	courseRepository = CourseRepository::getInstance();
}
