#include "../../Headers/Commands/PrintStudentGrades.h"

void PrintStudentGrades::execute() const
{
	const User* user = userRepository->getLoggedUserConst();

	if (!user)
	{
		throw std::invalid_argument("Log in first!");
	}
	if (!user->isStudent())
	{
		throw std::invalid_argument("Only students have grades!");
	}

	courseRepository->printGrades(user->getId());
}