/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class ChangePassword : public Command
{
public:
	ChangePassword() = default;
	virtual void execute() const override;
};
