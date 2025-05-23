/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "../Repositories/UserRepository.h"
#include "../Repositories/CourseRepository.h"

class Command
{
public:
	Command();
	virtual void execute() const = 0;
	virtual ~Command() = default;

protected:
	UserRepository* userRepository;
	CourseRepository* courseRepository;
};