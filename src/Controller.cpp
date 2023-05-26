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

void Controller::adminController()
{
}

void Controller::userController(HashTable *customer, University universityList[], int *univIndex, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> feedbackList, User currentUser)
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
			favouriteController(customer, favUser, ui, universityList, univIndex, top10);
			break;
		case 5:
			// Feedback controller - eugene
			feedbackController(feedbackList, ui, currentUser);
			break;
		case 6:
			ui.clearScreen();
			return;
		case 0:
			exit(0);
		default:
			return;
			break;
		}
	}
}

void Controller::favouriteController(HashTable *customer, User *currentUser, UI ui, University universityList[], int *univIndex, DynamicArray<University> *top10)
{
	ui.clearScreen();
	while (true)
	{
		ui.favouriteMenu();
		int userChoice;
		int uniChoice;
		LinkedList<University> favList = currentUser->getFavUnivList();
		std::cin.clear();
		std::cin.ignore();
		std::cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			ui.universityHeader();
			favList.show();
			break;
		case 2:
			ui.universityList(universityList, univIndex);
			std::cout << "Please provide the rank of the university you want to add: ";
			std::cin >> uniChoice;
			if (uniChoice == 0)
			{
				std::cout << "Invalid choice" << std::endl;
				continue;
			}
			if (favList.insertAtEnd(universityList[uniChoice - 1]))
			{
				top10->append(universityList[uniChoice - 1]);
			};
			currentUser->setFavUnivList(favList);
			customer->removeUser(currentUser->getUsername());
			customer->addUser(*currentUser);
			std::cout << " ----- DYNAMIC ARRAY ----- " << std::endl;
			top10->show();
			break;
		case 3:
			ui.universityHeader();
			favList.show();
			std::cout << "Please provide the rank of the university you want to remove: ";
			std::cin >> uniChoice;
			if (uniChoice == 0)
			{
				std::cout << "Invalid choice" << std::endl;
				continue;
			}
			favList.removeItem(universityList[uniChoice - 1]);
			top10->remove(universityList[uniChoice - 1]);
			currentUser->setFavUnivList(favList);
			break;
		case 4:
			return;
		case 5:
			exit(1);
		default:
			std::cout << "Not an option" << std::endl;
			break;
		}
	}
}

void Controller::feedbackController(LinkedList<Feedback> feedbackList, UI ui, User currentUser)
{
	int userChoice;
	ui.clearScreen();
	Node<Feedback> *currentNode = feedbackList.getTail();
	Feedback current = currentNode->data;
	do
	{

		std::cout << "------------Feedback Lists------------";

		std::cout << current << std::endl;

		std::cout << "0. Move to previous feedback";
		std::cout << "\n1. Move to next feedback";
		std::cout << "\n2. Write a new feedback";
		std::cout << "\n3. Go back";

		std::cout << "\nPlease select an option: ";
		std::cin.ignore();
		std::cin.clear();
		std::cin >> userChoice;

		if (userChoice == 0)
		{
			ui.clearScreen();

			currentNode = feedbackList.navigateNodes(currentNode, 0);
			current = currentNode->data;
		}

		if (userChoice == 1)
		{
			ui.clearScreen();

			currentNode = feedbackList.navigateNodes(currentNode, 1);
			current = currentNode->data;
		}

		if (userChoice == 2)
		{

			std::string feedback;
			std::cout << "\n------------Feedback Lists------------";
			std::cout << "\nPlease enter your feedback: ";
			std::cin.ignore();
			std::cin >> feedback;

			int newID = feedbackList.getSize() + 1;
			std::string newUser = currentUser.getUsername();
			std::string newComment = feedback;
			std::time_t createdAt = std::time(nullptr);

			Feedback newFeedback = Feedback(newID, newUser, newComment, createdAt);
			feedbackList.insertAtEnd(newFeedback);
			ui.clearScreen();
			currentNode = feedbackList.getTail();
			current = currentNode->data;
		}

		if (userChoice == 3)
			break;
	} while (true);
}
