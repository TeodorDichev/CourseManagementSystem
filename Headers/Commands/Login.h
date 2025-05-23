/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class Login : public Command
{
public:
	Login() = default;
	virtual void execute() const override;
};
