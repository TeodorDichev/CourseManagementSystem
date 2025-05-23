#pragma once
#include "Command.h"

class SubmitAssignment : public Command
{
public:
	SubmitAssignment() = default;
	virtual void execute() const override;
};
