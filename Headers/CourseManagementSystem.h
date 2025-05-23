/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "Commands/CommandFactory.h"
#include "Utills/SerializeFunctions.h"
#include "Repositories/UserRepository.h"
#include "Repositories/CourseRepository.h"

class CourseManagementSystem
{
public:
	CourseManagementSystem() = default;
	void Run();
};

