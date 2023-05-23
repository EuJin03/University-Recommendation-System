#include "../include/UI.h"
#include "../include/Seeder.h"
#include "../include/DynamicArray.h"
#include "../include/Algorithms.h"

using namespace std::chrono;

int main()
{
	UI ui;
	Seeder seeder;

	DynamicArray<University> universityList;
	seeder.createUnivInstances(&universityList);

	// Quick sort demo
	Algorithms algorithm;
	algorithm.countSort(universityList, Algorithms::FSR_SCORE);
	universityList.show(ui);

	LinkedList<Feedback> feedbackList;
	seeder.createFeedbackInstances(&feedbackList);

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

		switch (option)
		{
		case 1:
			// Display all universities' information
			universityList.show(ui);
			break;
		case 2:
			ui.userSortMenu();
			// should move into controller class
			std::cin >> sortOption;
			switch (sortOption)
			{
			case 1:
				// Sort by Institution name
				// universityList.sortByName();
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