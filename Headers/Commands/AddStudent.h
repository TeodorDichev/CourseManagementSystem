/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class AddStudent : public Command
{
public:
	AddStudent() = default;
	virtual void execute() const override;
};
