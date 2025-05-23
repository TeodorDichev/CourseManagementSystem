#pragma once
#include "Command.h"

class Login : public Command
{
public:
	Login() = default;
	virtual void execute() const override;
};
