/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class PrintStudentGrades : public Command
{
public:
	PrintStudentGrades() = default;
	virtual void execute() const override;
};
