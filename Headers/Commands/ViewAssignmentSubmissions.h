/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class ViewAssignmentSubmissions : public Command
{
public:
	ViewAssignmentSubmissions() = default;
	virtual void execute() const override;
};
