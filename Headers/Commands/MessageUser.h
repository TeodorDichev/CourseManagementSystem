/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class MessageUser : public Command
{
public:
	MessageUser() = default;
	virtual void execute() const override;
};
