/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class MessageStudents : public Command
{
public:
	MessageStudents() = default;
	virtual void execute() const override;
};
