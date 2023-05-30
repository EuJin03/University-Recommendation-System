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

	// Initialize variables
	int univIndex = 0;
	int ARRAY_SIZE = 1422;
	University universityList[ARRAY_SIZE];
	University unsortedUniversityList[ARRAY_SIZE];
	DynamicArray<University> top10;
	DynamicArray<University> uniqueUni;
	DynamicArray<int> uniqueUniCount;
	seeder.createUnivInstances(universityList);
	seeder.createUnivInstances(unsortedUniversityList);

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
		ui.clearScreen();
		ui.mainMenu();
		std::cin >> option;
		std::string searchCriteria;
		// Unregistered User
		int searchRank;
		switch (option)
		{
		case 1:
			// Display university list
			ui.clearScreen();
			ui.universityList(universityList, &univIndex);
			break;
		case 2:
			// Sort university list by institution name in ascending order
			ui.clearScreen();
			char command;
			// should move into controller class
			std::cout << " ---------- SORT ---------- " << std::endl;
			start_load = std::chrono::high_resolution_clock::now();
			algorithm.quickSort(universityList, 0, ARRAY_SIZE - 1, false, 2);
			end_load = std::chrono::high_resolution_clock::now();
			durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
			std::cout << "Time taken to load data using Quick Sort: " << durationLoad << " microseconds" << std::endl;

			algorithm.countSort(universityList, ARRAY_SIZE, Algorithms::SortType::RANK_SCORE, true);

			start_load = std::chrono::high_resolution_clock::now();
			algorithm.countSort(universityList, ARRAY_SIZE, Algorithms::SortType::INSTITUTION, true);
			end_load = std::chrono::high_resolution_clock::now();
			durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
			std::cout << "Time taken to load data using Count Sort: " << durationLoad << " microseconds" << std::endl;

			std::cout << "\nInput anything to go back to main menu:";
			std::cin >> command;

			break;
		case 3:
			// Search university
			ui.clearScreen();
			controller.searchController(universityList, &univIndex, ARRAY_SIZE, ui, &currentUser, &top10, &feedbackList, currentUser);
			break;
		case 4:
			// Register
			ui.clearScreen();
			std::cout << " ---------- REGISTER ---------- " << std::endl;
			do
			{
				std::cout << "Enter username: ";
				std::cin >> username;
				std::cout << "Enter password: ";
				std::cin >> password;
			} while (!controller.registerUser(username, password, &customer));

			std::cout << "Registration successful!" << std::endl;
			std::cout << "\nInput anything to go back to main menu:";
			std::cin >> command;
			break;
			break;
		case 5:
			// Login
			ui.clearScreen();
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
					currentUser.setLastLogin(std::time(nullptr));
					customer.removeUser(username);
					customer.addUser(currentUser);
					if (currentUser.getIsAdmin())
					{
						// Admin
						controller.adminController(ui, universityList, &univIndex, &customer, &feedbackList, currentUser, &top10); // -- eugene & bryan
					}
					else
					{
						// Registered User
						controller.userController(&customer, universityList, &univIndex, ARRAY_SIZE, ui, &currentUser, &top10, &feedbackList, currentUser);
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