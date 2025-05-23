/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class ClearMailBox : public Command
{
public:
	ClearMailBox() = default;
	virtual void execute() const override;
};
