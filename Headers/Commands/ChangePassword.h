#pragma once
#include "Command.h"

class ChangePassword : public Command
{
public:
	ChangePassword() = default;
	virtual void execute() const override;
};
