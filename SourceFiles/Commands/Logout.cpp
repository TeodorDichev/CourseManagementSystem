#include "../../Headers/Commands/Logout.h"

void Logout::execute() const
{
	userRepository->logOutUser();
	std::cout << "Logged out successfully!" << std::endl << std::endl;
}
