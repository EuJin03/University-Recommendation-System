#include "../include/Controller.h"

std::string Controller::validate(std::string username, std::string password)
{
	if (username.length() < 6)
	{
		return "Username must be at least 6 characters long";
	}
	else if (password.length() < 6)
	{
		return "Password must be at least 6 characters long";
	}
	else
	{
		return "success";
	}
}

void Controller::userController(University universityList[], int *univIndex, UI ui, LinkedList<Feedback> feedbackList, User currentUser)
{
	while (true)
	{
		ui.customerMenu();
		int userChoice;
		std::cin.ignore();
		std::cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			// Display all universities' information
			ui.universityList(universityList, univIndex);
			break;
		case 2:
			// Sort University - pc
			break;
		case 3:
			// Search university - pc
			break;
		case 4:
			// Favourite controller - bryan
			break;
		case 5:
			// Feedback controller - eugene
			feedbackController(feedbackList, ui, currentUser);
			break;
		case 6:
			ui.clearScreen();
			return;
			break;
		case 0:
			exit(0);
			break;
		default:
			return;
			break;
		}
	}
}

void Controller::feedbackController(LinkedList<Feedback> feedbackList, UI ui, User currentUser)
{
	int userChoice;
	ui.clearScreen();

	std::cin.ignore();
	std::cin.clear();
	std::cin >> userChoice;
	Feedback current = feedbackList.getTail();

	std::cout << "------------Feedback Lists------------";
	while (true)
	{
		std::cout << "\tFeedback ID: " << current.getFeedbackID() << std::endl;
		std::cout << "\tUser: " << current.getUsername() << std::endl;
		std::cout << current.getFeedback() << std::endl;
	}
}

void Controller::adminController()
{
}