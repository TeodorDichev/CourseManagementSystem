/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class GetMailBox : public Command
{
public:
	GetMailBox() = default;
	virtual void execute() const override;
};
