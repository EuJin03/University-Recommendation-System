#include "../include/UI.h"
#include "../include/Seeder.h"
#include "../include/DynamicArray.h"
#include "../include/Algorithms.h"
#include "../include/LinkedList.h"
#include "../include/Controller.h"
#include <string>

int main()
{
	UI ui;
	Seeder seeder;
	Controller controller;

	int univIndex = 0;
	int ARRAY_SIZE = 1422;
	University universityList[ARRAY_SIZE];
	static int feedbackID = 0;
	DynamicArray<University> top10;
	seeder.createUnivInstances(universityList);

	// Quick sort demo
	Algorithms algorithm;
	auto start_load = std::chrono::high_resolution_clock::now();
	auto end_load = std::chrono::high_resolution_clock::now();
	long long durationLoad;

	LinkedList<Feedback> feedbackList;
	seeder.createFeedbackInstances(&feedbackList);

	LinkedList<University> favUnivList;
	// seeder.createFavUnivInstances(&favUnivList);

	HashTable customer(50);
	seeder.createUserInstances(&customer);

	User currentUser;
	std::string username, password;

	int option, sortOption;
	while (true)
	{
		ui.mainMenu();
		std::cin >> option;
		std::string searchCriteria;
		// Unregistered User
		switch (option)
		{
		case 1:
			// Display all universities' information
			ui.universityList(universityList, &univIndex);
			break;
		case 2:
			// should move into controller class
            start_load = std::chrono::high_resolution_clock::now();
            algorithm.quickSort(universityList, 0, ARRAY_SIZE - 1, false, 2);
            end_load = std::chrono::high_resolution_clock::now();
            durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
            std::cout << "Time taken to load data using Quick Sort: " << durationLoad << " microseconds" << std::endl;

            algorithm.countSort(universityList, ARRAY_SIZE, Algorithms::SortType::RANK_SCORE);

            start_load = std::chrono::high_resolution_clock::now();
            algorithm.countSort(universityList, ARRAY_SIZE, Algorithms::SortType::AR_SCORE);
            end_load = std::chrono::high_resolution_clock::now();
            durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
            std::cout << "Time taken to load data using Count Sort: " << durationLoad << " microseconds" << std::endl;

			break;
		case 3:
			// Search university
			std::cout << "Enter the institution name you want to search: ";
			std::cin.ignore();
			std::getline(std::cin, searchCriteria);
			algorithm.linearSearch(universityList, ARRAY_SIZE, 1, searchCriteria);

			break;
		case 4:
			// Register
			break;
		case 5:
			// Login
			std::cout << " ---------- LOGIN ---------- " << std::endl;
			while (true)
			{
				std::cout << "Username: ";
				std::cin >> username;
				std::cout << "Password: ";
				std::cin >> password;
				if (customer.verifyUser(username, password))
				{
					currentUser = customer.getUser(username);
					if (currentUser.getIsAdmin())
					{
						// Admin
						controller.adminController(ui, universityList, &univIndex, &customer);
					}
					else
					{
						// Registered User
						controller.userController(&customer, universityList, &univIndex, ui, &currentUser, &top10, feedbackList, currentUser);
					}
					break;
				}
				else
				{
					std::cout << "Incorrect username or password. Please try again!" << std::endl;
				}
			}
			break;
		case 0:
			return 0; // Ends the program
		default:
			ui.invalidOptionMsg();
		}
	}

	return 0;
}

/**
	system("cls");
	time_t now = time(0);
	tm* current_time = localtime(&now);

	auto start_load = high_resolution_clock::now();
	auto end_load = high_resolution_clock::now();
	long long durationLoad = duration_cast<std::chrono::microseconds>(end_load - start_load).count();
	std::cout << "Time taken to load data: " << durationLoad << " microseconds" << std::endl;

	Seeder seeder;
	seeder.createFeedbackInstances();
	seeder.createUnivInstances();
	seeder.createUserInstances();
	seeder.createDynamicArrayInstance();
 */