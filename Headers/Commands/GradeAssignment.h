#pragma once
#include "Command.h"

class GradeAssignment : public Command
{
public:
	GradeAssignment() = default;
	virtual void execute() const override;
};
