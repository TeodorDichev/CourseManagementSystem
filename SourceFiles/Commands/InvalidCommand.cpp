#include "InvalidCommand.h"

void InvalidCommand::execute() const
{
	std::cerr << "Invalid command!" << std::endl;
}