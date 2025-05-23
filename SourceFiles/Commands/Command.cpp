/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/Command.h"

Command::Command()
{
	userRepository = UserRepository::getInstance();
	courseRepository = CourseRepository::getInstance();
}
