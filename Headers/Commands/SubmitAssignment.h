/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class SubmitAssignment : public Command
{
public:
	SubmitAssignment() = default;
	virtual void execute() const override;
};
