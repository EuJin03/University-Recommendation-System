#include <chrono>
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

auto startTimer = []() {
	return std::chrono::high_resolution_clock::now();
};

auto endTimer = [](auto start_load) {
	auto end_load = std::chrono::high_resolution_clock::now();
	long long durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
	std::cout << "Time taken to load: " << durationLoad << " microseconds" << std::endl;
};

bool Controller::registerUser(std::string username, std::string password, HashTable *userTable)
{
    if (validate(username, password) != "success")
    {
        std::cout << "Register Failed \nPlease try again with username and password length of at least 6 characters."
                  << std::endl;
        return false;
    } else {
        std::time_t lastLogin = std::time(nullptr);
        bool isAdmin = false;
        User user(username, password, lastLogin, isAdmin);
        userTable->addUser(user);
    }
    return true;
}

void Controller::adminController(UI ui, University universityList[], int *univIndex, HashTable *customer,
                                 LinkedList<Feedback> *feedbackList, User currentUser,
                                 DynamicArray<University> *top10,
                                 DynamicArray<University> *uniqueUni, DynamicArray<int> *uniqueUniCount) {
    while (true) {
        ui.adminMenu();
        int userChoice;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> userChoice;

        switch (userChoice) {
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
                // Display top 10
                top10Controller(top10, *uniqueUni, *uniqueUniCount);
                break;
            case 5:
                // Logout
                ui.clearScreen();
                return;
            case 6:
                // Exit
                exit(0);
            default:
                break;
        }
    }
}

void Controller::modifyController(UI ui, HashTable *customer) {
    ui.clearScreen();
    while (true) {
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
        switch (modifyChoice) {
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

                if (deleteChoice == 'y') {
                    customer->deleteInactiveAccounts();
                    ui.clearScreen();
                } else {
                    ui.clearScreen();
                }
                break;
            case 4:
                ui.clearScreen();
                return;
            case 5:
                exit(0);
            default:
                ui.clearScreen();
                std::cout << "Invalid option\n\n";
                break;
        }
    }
}

void Controller::top10Controller(DynamicArray<University> *top10, DynamicArray<University> uniqueUni,
                                 DynamicArray<int> uniqueUniCount) {
    int userChoice;
    for (int i = 0; i < top10->getSize(); i++) {
        if (uniqueUni.contains(top10->get(i))) {
            int index = uniqueUni.find(top10->get(i));
            uniqueUniCount.set(uniqueUniCount.getValue(index) + 1, index);
        } else {
            uniqueUni.append(top10->get(i));
            uniqueUniCount.append(1);
        }
    }

    for (int i = 0; i < 10; i++) {
        std::cout << uniqueUni.get(i).getInstitution() << " : " << uniqueUniCount.get(i) << std::endl;
    }
    std::cin >> userChoice;
}

void Controller::userController(HashTable *customer, University universityList[], int *univIndex,int size, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> feedbackList, User currentUser)
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
			sortController(universityList, univIndex, size, ui, favUser, top10, feedbackList, currentUser);
			break;
		case 3:
			// Search university - pc
			searchController(universityList, univIndex, size, ui, favUser, top10, feedbackList, currentUser);
			break;
		case 4:
			// Favourite controller - bryan
            favouriteController(customer, favUser, ui, universityList, univIndex, top10);
			break;
		case 5:
			// Feedback controller - eugene
			feedbackController(&feedbackList, ui, currentUser);
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

// to reduece sorting code
void sort(University universityList[], int SIZE, Algorithms algorithms, Algorithms::SortType sortType, int choice)
{
	
	auto startLoad = startTimer();
	// startLoad = std::chrono::high_resolution_clock::now();
	algorithms.quickSort(universityList, 0, SIZE - 1, true, choice);
	// endLoad = std::chrono::high_resolution_clock::now();
	// durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(endLoad - startLoad).count();
	std::cout << "Sorted with quick sort:" << std::endl;
	// std::cout << "Time taken to load: " << durationLoad << " microseconds" << std::endl;
	endTimer(startLoad);

	algorithms.countSort(universityList, SIZE, Algorithms::SortType::RANK_SCORE);

	algorithms.countSort(universityList, SIZE, Algorithms::SortType::RANK_SCORE);
	startLoad = startTimer();
	// auto startLoad = std::chrono::high_resolution_clock::now();
	algorithms.countSort(universityList, SIZE, sortType);
	// auto endLoad = std::chrono::high_resolution_clock::now();
	// long long durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(endLoad - startLoad).count();
	std::cout << "Sorted with count sort:" << std::endl;
	// std::cout << "Time taken to load: " << durationLoad << " microseconds" << std::endl;
	endTimer(startLoad);
}

void Controller::sortController(University universityList[], int *univIndex, int SIZE, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> feedbackList, User currentUser)
{
	Algorithms algorithms;
	ui.clearScreen();
	while(true)
	{
		ui.userSortMenu();
		int userChoice;
        std::cin.clear();
		std::cin.ignore();
		std::cin >> userChoice;

		ui.clearScreen();
		switch (userChoice)
		{
			case 1:
				// Sort by institution name
				sort(universityList, SIZE, algorithms, Algorithms::SortType::INSTITUTION, Algorithms::SortType::INSTITUTION);
				break;

			case 2:
				// Sort by FSR score
				sort(universityList, SIZE, algorithms, Algorithms::SortType::FSR_SCORE, Algorithms::SortType::FSR_SCORE);
				// algorithms.countSort(universityList, *univIndex, Algorithms::SortType::FSR_SCORE);
				break;

			case 3:
				// Sort by ER score
				sort(universityList, SIZE, algorithms, Algorithms::SortType::ER_SCORE, Algorithms::SortType::ER_SCORE);
				break;

			case 4:
				// Sort by AR score
				sort(universityList, SIZE, algorithms, Algorithms::SortType::AR_SCORE, Algorithms::SortType::AR_SCORE);
				break;

			case 5:
				// Sort by FSR rank
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::FSR_RANK_SORT);
				break;

			case 6:
				// Sort by ER rank
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::ER_RANK_SORT);
				break;

			case 7:
				// Sort by AR rank
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::AR_RANK_SORT);
				break;

			case 8:
				return;

			default:
				std::cout << "Invalid input" << std::endl;
				break;
		}
	}
}

void searchInt(University universityList[], int size, Algorithms algorithms, std::string searchCriteria, int choice, int searchCriteriaInt)
{
    // Binary search for integer
	auto startLoad = startTimer();
	algorithms.binarySearchWithDuplicates(universityList, size, choice, searchCriteriaInt);
	endTimer(startLoad);
    std::cout << "Searched with binary search:" << std::endl;
	// Linear search for integer
	// ******************************************************
	startLoad = startTimer();
	algorithms.linearSearch(universityList, size, 3, searchCriteria);
	endTimer(startLoad);
    std::cout << "Searched with linear search:" << std::endl;
	
}

void Controller::searchController(University universityList[], int *univIndex, int SIZE, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> feedbackList, User currentUser)
{
	Algorithms algorithms;
	ui.clearScreen();
	while(true)
	{
		ui.userSearchMenu();
		int userChoice;
        std::cin.clear();
		std::cin.ignore();
		std::cin >> userChoice;

		std::string searchCriteria;
		int searchCriteriaInt;
		ui.clearScreen();
        auto startLoad = startTimer();
		switch (userChoice)
		{
			case 1:
				// Search by institution name
				std::cout << "Enter the institution name you want to search: ";
				std::cin.ignore();
				std::getline(std::cin, searchCriteria);
                startLoad = startTimer();   // is the start timer here correct? 
				algorithms.linearSearch(universityList, SIZE, 1, searchCriteria);
                endTimer(startLoad);
				break;

			case 2:
				// Search by Locale
				std::cout << "Enter the locale you want to search: ";
				std::cin.ignore();
				std::getline(std::cin, searchCriteria);
                startLoad = startTimer();
				algorithms.linearSearch(universityList, SIZE, 2, searchCriteria);
                endTimer(startLoad);
				break;

			case 3:
				// Search by Rank
				std::cout << "Enter the rank you want to search: ";
				std::cin >> searchCriteriaInt;
                searchCriteria = std::to_string(searchCriteriaInt);
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::RANK_SCORE);
				std::cout << "Done sort" << std::endl;
				searchInt(universityList, SIZE, algorithms, searchCriteria, Algorithms::SearchType::RANK, searchCriteriaInt);
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::RANK_SCORE);
				//searchInt(universityList, SIZE, algorithms, searchCriteria, Algorithms::SearchType::RANK, searchCriteriaInt);
				break;

			case 4:
				// Search by Faculty Student Ratio Rank
				std::cout << "Enter the FSR rank you want to search: ";
				std::cin >> searchCriteriaInt;
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::FSR_RANK_SORT);
				std::cout << "Done sort" << std::endl;

				searchInt(universityList, SIZE, algorithms, searchCriteria, Algorithms::SearchType::FSR_RANK, searchCriteriaInt);
				break;
			case 5:
				// Search by Employer Reputation Rank
				std::cout << "Enter the ER rank you want to search: ";
				std::cin >> searchCriteriaInt;
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::ER_RANK_SORT);
				std::cout << "Done sort" << std::endl;
				searchInt(universityList, SIZE, algorithms, searchCriteria, Algorithms::SearchType::ER_RANK, searchCriteriaInt);
				break;

			case 6:
				// Search by Academic Reputation Rank
				std::cout << "Enter the AR rank you want to search: ";
				std::cin >> searchCriteriaInt;
				algorithms.countSort(universityList, SIZE, Algorithms::SortType::AR_RANK_SORT);
				std::cout << "Done sort" << std::endl;

				searchInt(universityList, SIZE, algorithms, searchCriteria, Algorithms::SearchType::AR_RANK, searchCriteriaInt);
				break;

			case 7:
				return;

			case 0:
				exit(0);

			default:
				std::cout << "Invalid input" << std::endl;
				break;
		}
	}
}

void Controller::favouriteController(HashTable *customer, User *currentUser, UI ui, University universityList[], int *univIndex, DynamicArray<University> *top10)
{
    ui.clearScreen();
    while (true) {
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

void Controller::feedbackController(LinkedList<Feedback> *feedbackList, UI ui, User currentUser) {
    int userChoice;
    ui.clearScreen();
    Node<Feedback> *currentNode = feedbackList->getTail();
    Feedback current = currentNode->data;
    do {

        std::cout << "------------Feedback Lists------------";

        std::cout << current << std::endl;

        std::cout << "0. Move to previous feedback";
        std::cout << "\n1. Move to next feedback";
        if (currentUser.getIsAdmin()) {
            std::cout << "\n2. Reply to feedback";
        } else {
            std::cout << "\n2. Write a new feedback";
            
        }
        std::cout << "\n3. Go back";

        std::cout << "\nPlease select an option: ";
//		std::cin.ignore();
        std::cin.clear();
        std::cin >> userChoice;

        if (userChoice == 0) {
            ui.clearScreen();

            currentNode = feedbackList->navigateNodes(currentNode, 0);
            current = currentNode->data;
        }

        if (userChoice == 1) {
            ui.clearScreen();

            currentNode = feedbackList->navigateNodes(currentNode, 1);
            current = currentNode->data;
        }

        if (userChoice == 2) {

            if (currentUser.getIsAdmin()) {
                std::string reply;
                std::cout << "\n------------Reply Feedback------------";
                std::cout << "\nPlease enter your reply: ";
                std::cin.ignore();
                std::getline(std::cin, reply);

                Feedback newFeedback(current.getFeedbackID(), current.getUsername(), current.getFeedback(),
                                     current.getCreatedAt(), currentUser.getUsername(), reply, std::time(nullptr));
                feedbackList->updateItem(current, newFeedback);

                ui.clearScreen();
                current = currentNode->data;
            } else {
                std::string feedback;
                std::cout << "\n------------Feedback Lists------------";
                std::cout << "\nPlease enter your feedback: ";
                std::cin.ignore();
                std::getline(std::cin, feedback);

                int newID = feedbackList->getSize() + 1;
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