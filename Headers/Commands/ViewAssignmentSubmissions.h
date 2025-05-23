#pragma once
#include "Command.h"

class ViewAssignmentSubmissions : public Command
{
public:
	ViewAssignmentSubmissions() = default;
	virtual void execute() const override;
};
