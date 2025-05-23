/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class AddToCourse : public Command
{
public:
	AddToCourse() = default;
	virtual void execute() const override;
};
