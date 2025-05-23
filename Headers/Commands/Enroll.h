/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class Enroll : public Command
{
public:
	Enroll() = default;
	virtual void execute() const override;
};
