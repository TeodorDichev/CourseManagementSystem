#pragma once
#include "Command.h"

class CreateCourse : public Command
{
public:
	CreateCourse() = default;
	virtual void execute() const override;
};
