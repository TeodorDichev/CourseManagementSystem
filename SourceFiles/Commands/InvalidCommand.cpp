/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Commands/InvalidCommand.h"

void InvalidCommand::execute() const
{
	std::cerr << "Invalid command!" << std::endl;
}