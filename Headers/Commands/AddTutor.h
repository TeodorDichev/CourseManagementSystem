#pragma once
#include "Command.h"

class AddTutor : public Command
{
public:
	AddTutor() = default;
	virtual void execute() const override;
};
