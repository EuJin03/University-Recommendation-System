#include "../include/Controller.h"

#include <stdlib.h>

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

void Controller::userController(HashTable *customer, University universityList[], int *univIndex, UI ui, User *currentUser, DynamicArray<University> *top10)
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
            favouriteController(customer, currentUser, ui, universityList, univIndex, top10);
			break;
		case 5:
			// Feedback controller - eugene
			break;
		case 6:
			ui.clearScreen();
			return;
		case 0:
			exit(0);
		default:
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