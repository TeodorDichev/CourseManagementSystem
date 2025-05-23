#include "../../Headers/Commands/InvalidCommand.h"

void InvalidCommand::execute() const
{
	std::cerr << "Invalid command!" << std::endl;
}