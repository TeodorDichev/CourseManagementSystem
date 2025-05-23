#pragma once
#include "Command.h"

class ClearMailBox : public Command
{
public:
	ClearMailBox() = default;
	virtual void execute() const override;
};
