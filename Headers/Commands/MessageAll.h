/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Command.h"

class MessageAll : public Command
{
public:
    MessageAll() = default;
    virtual void execute() const override;
};
