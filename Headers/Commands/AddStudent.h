#pragma once
#include "Command.h"

class AddStudent : public Command
{
public:
	AddStudent() = default;
	virtual void execute() const override;
};
