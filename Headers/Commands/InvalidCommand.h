#pragma once
#include "Command.h"

class InvalidCommand : public Command
{
public:
	InvalidCommand() = default;
	virtual void execute() const override;
};
