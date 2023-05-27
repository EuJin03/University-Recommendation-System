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

bool Controller::registerUser(std::string username, std::string password, HashTable *userTable)
{
	if (validate(username, password) != "success")
	{
		std::cout << "Register Failed \nPlease try again with username and password length of at least 6 characters." << std::endl;
		return false;
	}
	else
	{
		std::time_t lastLogin = std::time(nullptr);
		bool isAdmin = false;
		User user(username, password, lastLogin, isAdmin);
		userTable->addUser(user);
	}
	return true;
}

void Controller::adminController(UI ui, University universityList[], int *univIndex, HashTable *customer, LinkedList<Feedback> *feedbackList, User currentUser)
{
	while (true)
	{
		ui.adminMenu();
		int userChoice;
		std::cin.clear();
		std::cin.ignore();
		std::cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			// Display University
			ui.universityList(universityList, univIndex);
			break;
		case 2:
			// Display user
			modifyController(ui, customer);
			break;
		case 3:
			// Display feedback
			feedbackController(feedbackList, ui, currentUser);
			break;
		case 4:
			// Logout
			ui.clearScreen();
			return;
		case 5:
			// Exit
			exit(0);
		default:
			break;
		}
	}
}

void Controller::modifyController(UI ui, HashTable *customer)
{
	ui.clearScreen();
	while (true)
	{
		std::string oldUsername, newUsername;
		std::string newPassword;
		int modifyChoice;
		char deleteChoice;
		char upgradeChoice;
		User selectedUser;

		customer->printAllUsersDetails();
		ui.modifyUserMenu();
		std::cin.clear();
		std::cin.ignore();
		std::cin >> modifyChoice;
		switch (modifyChoice)
		{
		case 1:
			// Change username
			// Getting user
			std::cout << "Enter original username: ";
			std::cin >> oldUsername;
			selectedUser = customer->getUser(oldUsername);

			// Removing user from HashTable
			customer->removeUser(oldUsername);

			// Getting new username
			std::cin.ignore();
			std::cout << "Enter new username: ";
			std::cin >> newUsername;
			selectedUser.setUsername(newUsername);

			// Saving user back to HashTable
			customer->addUser(selectedUser);
			ui.clearScreen();
			break;
		case 2:
			// Change password
			// Getting user
			std::cout << "Enter username: ";
			std::cin.ignore();
			std::cin >> oldUsername;
			selectedUser = customer->getUser(oldUsername);

			// Removing user record from HashTable
			customer->removeUser(oldUsername);

			// Getting old password
			std::cout << "Enter new password: ";
			std::cin.ignore();
			std::cin >> newPassword;
			selectedUser.setPassword(newPassword);

			// Saving user back to HashTable
			customer->addUser(selectedUser);
			ui.clearScreen();
			break;
		case 3:
			// Delete Inactive Users
			std::cout << "Are you sure you want to delete [y/n]: ";
			std::cin >> deleteChoice;

			if (deleteChoice == 'y')
			{
				customer->deleteInactiveAccounts();
				ui.clearScreen();
			}
			else
			{
				ui.clearScreen();
			}
			break;
		case 4:
			std::cout << "\nAre you sure you want to upgrade this user to admin? [y/N]";
			std::cin >> upgradeChoice;

			if (upgradeChoice)
			{
			}
			else
			{
				ui.clearScreen();
			}

			break;
		case 5:
			exit(0);
		default:
			ui.clearScreen();
			std::cout << "Invalid option\n\n";
			break;
		}
	}
}

void Controller::userController(HashTable *customer, University universityList[], int *univIndex, UI ui, User *favUser,
																DynamicArray<University> *top10, LinkedList<Feedback> *feedbackList, User currentUser)
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
			// Display all universities' information - eugene
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
			std::cout << "Not an option" << std::endl;
			break;
		}
	}
}

void Controller::favouriteController(HashTable *customer, User *currentUser, UI ui, University universityList[],
																		 int *univIndex, DynamicArray<University> *top10)
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
			ui.clearScreen();
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
			ui.clearScreen();
			break;
		case 4:
			ui.clearScreen();
			return;
		case 5:
			exit(1);
		default:
			std::cout << "Not an option" << std::endl;
			break;
		}
	}
}

void Controller::feedbackController(LinkedList<Feedback> *feedbackList, UI ui, User currentUser)
{
	int userChoice;
	ui.clearScreen();
	Node<Feedback> *currentNode = feedbackList->getTail();
	Feedback current = currentNode->data;
	do
	{

		std::cout << "------------Feedback Lists------------";

		std::cout << current << std::endl;

		std::cout << "0. Move to previous feedback";
		std::cout << "\n1. Move to next feedback";
		if (currentUser.getIsAdmin())
		{
			std::cout << "\n2. Reply to feedback";
		}
		else
		{
			std::cout << "\n2. Write a new feedback";
		}
		std::cout << "\n3. Go back";

		std::cout << "\nPlease select an option: ";
		//		std::cin.ignore();
		std::cin.clear();
		std::cin >> userChoice;

		if (userChoice == 0)
		{
			ui.clearScreen();

			currentNode = feedbackList->navigateNodes(currentNode, 0);
			current = currentNode->data;
		}

		if (userChoice == 1)
		{
			ui.clearScreen();

			currentNode = feedbackList->navigateNodes(currentNode, 1);
			current = currentNode->data;
		}

		if (userChoice == 2)
		{

			if (currentUser.getIsAdmin())
			{
				std::string reply;
				std::cout << "\n------------Reply Feedback------------";
				std::cout << "\nPlease enter your reply: ";
				std::cin.ignore();
				std::getline(std::cin, reply);

				Feedback newFeedback(current.getFeedbackID(), current.getUsername(), current.getFeedback(), current.getCreatedAt(), currentUser.getUsername(), reply, std::time(nullptr));
				feedbackList->updateItem(current, newFeedback);

				ui.clearScreen();
				current = currentNode->data;
			}
			else
			{
				std::string feedback;
				std::cout << "\n------------Feedback Lists------------";
				std::cout << "\nPlease enter your feedback: ";
				std::cin.ignore();
				std::getline(std::cin, feedback);

				int newID = feedbackList->getSize();
				std::string newUser = currentUser.getUsername();
				std::string newComment = feedback;
				std::time_t createdAt = std::time(nullptr);

				Feedback newFeedback = Feedback(newID, newUser, newComment, createdAt);
				feedbackList->insertAtEnd(newFeedback);
				ui.clearScreen();
				currentNode = feedbackList->getTail();
				current = currentNode->data;
			}
		}

		if (userChoice == 3)
			break;
	} while (true);
}
