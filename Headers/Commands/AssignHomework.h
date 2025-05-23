#pragma once
#include "Command.h"

class AssignHomework : public Command
{
public:
	AssignHomework() = default;
	virtual void execute() const override;
};
