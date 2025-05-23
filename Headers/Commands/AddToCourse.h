#pragma once
#include "Command.h"

class AddToCourse : public Command
{
public:
	AddToCourse() = default;
	virtual void execute() const override;
};
