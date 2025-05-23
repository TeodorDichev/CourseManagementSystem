#pragma once
#include "Command.h"

class MessageStudents : public Command
{
public:
	MessageStudents() = default;
	virtual void execute() const override;
};
