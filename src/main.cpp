#include "../include/UI.h"
#include "../include/Seeder.h"
#include "../include/DynamicArray.h"
#include "../include/Algorithms.h"
#include <string>

int main()
{
	UI ui;
	Seeder seeder;

	int univIndex = 0;
	int ARRAY_SIZE = 1422;
	University universityList[ARRAY_SIZE];
	DynamicArray<University> top10;
	seeder.createUnivInstances(universityList);

	// Quick sort demo
	Algorithms algorithm;
	auto start_load = std::chrono::high_resolution_clock::now();
	algorithm.countSort(universityList, ARRAY_SIZE, Algorithms::SortType::INSTITUTION);
	//    algorithm.quickSort(universityList, 0, universityList.size() - 1, true, 1);
	//	ui.universityList(universityList, &./univIndex);
	auto end_load = std::chrono::high_resolution_clock::now();
	long long durationLoad = std::chrono::duration_cast<std::chrono::microseconds>(end_load - start_load).count();
	std::cout << "Time taken for counting sort: " << durationLoad << " microseconds" << std::endl;

	// ui.universityList(universityList, &univIndex);

	// LinkedList<Feedback> feedbackList;
	// seeder.createFeedbackInstances(&feedbackList);

	LinkedList<University> favUnivList;
	// seeder.createFavUnivInstances(&favUnivList);

	HashTable customer(50);
	seeder.createUserInstances(&customer);

	User *currentUser = nullptr;

	int option, sortOption;
	while (true)
	{
		ui.mainMenu();
		std::cin >> option;
		std::string searchCriteria;
		switch (option)
		{
		case 1:
			// Display all universities' information
			ui.universityList(universityList, &univIndex);
			break;
		case 2:
			ui.userSortMenu();
			// should move into controller class
			std::cin >> sortOption;
			switch (sortOption)
			{
			case 1:
				
				break;
			case 2:
				break;
			case 3:

				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
			}
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
				algorithm.linearSearch(universityList, ARRAY_SIZE,1, searchCriteria);
				break;
			case 2:	
				// Search by Locale
				std::cout << "Enter the locale you want to search: ";
				std::cin.ignore();
				std::getline(std::cin, searchCriteria);
				algorithm.linearSearch(universityList, ARRAY_SIZE,2, searchCriteria);
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

			break;
		case 5:
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