#include "../include/UI.h"
#include "../include/Seeder.h"
#include "../include/DynamicArray.h"
#include "../include/Algorithms.h"
#include "../include/LinkedList.h"
#include "../include/Controller.h"
#include <string>
#include<bits/stdc++.h>

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
	//	algorithm.countSort(universityList, Algorithms::SortType::AR_SCORE);
	// algorithm.quickSort(universityList, 0, ARRAY_SIZE - 1, true, 2);
	// ui.universityList(universityList, &univIndex);
	auto end_load = std::chrono::high_resolution_clock::now();
	long long durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
	// std::cout << "Time taken for counting sort: " << durationLoad << " microseconds" << std::endl;

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
			ui.userSortMenu();
			// should move into controller class
			break;
		case 3:
			//Search university
			
			ui.userSearchMenu();
			std::cin >> option;
			switch (option)
			{case 1:
				// Search by Institution name
				// universityList.sortByName();
				std::cout << "Enter the institution name you want to search: ";
				std::cin.ignore();
				std::getline(std::cin, searchCriteria);
				ui.universityHeader();
				std::cout << std::string(175,'-') << std::endl;
				start_load = std::chrono::high_resolution_clock::now();
				algorithm.linearSearch(universityList, ARRAY_SIZE,1, searchCriteria);
				end_load = std::chrono::high_resolution_clock::now();
				durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
				std::cout << "Time taken for linear search to complete: " << durationLoad << " microseconds" << std::endl;
				break;
			case 2:
				// Search by Locale
				std::cout << "Enter the locale you want to search: ";
				std::cin.ignore();
				std::getline(std::cin, searchCriteria);
				start_load = std::chrono::high_resolution_clock::now();
				algorithm.linearSearch(universityList, ARRAY_SIZE,2, searchCriteria);
				end_load = std::chrono::high_resolution_clock::now();
				durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
				std::cout << "Time taken for linear search to complete: " << durationLoad << " microseconds" << std::endl;
				break;
			case 3:
				// Search by Rank
				break;
			case 4:
				// Search by Employer Reputation score
				break;
			case 5:
				// Search by Academic Reputation scorecd..
				break;
			default:
				break;
			}

			break;
        case 4:
			// Register
			std::cout << " ---------- REGISTER ---------- " << std::endl;
    		std::cout << "Enter username: ";
    		std::cin >> username;
    		std::cout << "Enter password: ";
			std::cin >> password;
			if(!controller.registerUser(username, password, &customer)){
				std::cout << "Registration failed!" << std::endl;
			}else{
				std::cout << "Registration successful!" << std::endl;
			}
			
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
						controller.adminController(); // -- wenxuen
					}
					else
					{
						// Registered User
						controller.userController(&customer, universityList, &univIndex, ui, &currentUser, &top10);
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