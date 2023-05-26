#include "../include/UI.h"

void UI::mainMenu()
{
	std::cout << "Welcome to SURS!\n";
	std::cout << "\nMain Menu\n";
	std::cout << "1. Display all universities' information\n";
	std::cout << "2. Sort universities\n";
	std::cout << "3. Search university details\n";
	std::cout << "4. Register\n";
	std::cout << "5. Login\n";
	std::cout << "0. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::customerMenu()
{
	clearScreen();
	std::cout << "\nCustomer Menu\n";
	std::cout << "1. Display all universities' information\n";
	std::cout << "2. Sort universities\n";
	std::cout << "3. Search university\n";
	std::cout << "4. Favorite List\n";
	std::cout << "5. Feedbacks\n";
	std::cout << "6. Logout\n";
	std::cout << "0. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::adminMenu()
{
	clearScreen();
	std::cout << "\nAdmin Menu\n";
	std::cout << "1. Display all universities' information\n";
	std::cout << "2. Display all user details\n";
	std::cout << "3. Display feedback\n";
	std::cout << "4. Logout\n";
	std::cout << "5. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::userSortMenu()
{
	clearScreen();
	std::cout << "\nSort Menu\n";
	std::cout << "1. Sort by Institution name\n";
	std::cout << "2. Sort by Faculty/Student Ratio score\n";
	std::cout << "3. Sort by Employer Reputation score\n";
	std::cout << "4. Sort by Academic Reputation score\n";
	std::cout << "5. Return to main menu\n";
	std::cout << "0. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::userSearchMenu()
{
	std::cout << "\nSearch Menu\n";
	std::cout << "1. Search by Institution name\n";
	std::cout << "2. Search by Locale\n";
	std::cout << "3. Search by Rank\n";
	std::cout << "4. Search by Employer Reputation score\n";
	std::cout << "4. Search by Academic Reputation score\n";
	std::cout << "5. Return to main menu\n";
	std::cout << "0. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::universityHeader()
{
	clearScreen();
	std::cout << std::left << std::setw(5) << "Rank";
	std::cout << std::left << std::setw(60) << "Institution";
	std::cout << std::left << std::setw(10) << "Locale";
	std::cout << std::left << std::setw(15) << "Location";
	std::cout << std::left << std::setw(5) << "ArS";
	std::cout << std::left << std::setw(5) << "ArR";
	std::cout << std::left << std::setw(5) << "ErS";
	std::cout << std::left << std::setw(5) << "ErR";
	std::cout << std::left << std::setw(5) << "FsrS";
	std::cout << std::left << std::setw(5) << "FsrR";
	std::cout << std::left << std::setw(5) << "CpfS";
	std::cout << std::left << std::setw(5) << "CpfR";
	std::cout << std::left << std::setw(5) << "LfrS";
	std::cout << std::left << std::setw(5) << "LfrR";
	std::cout << std::left << std::setw(5) << "LsrS";
	std::cout << std::left << std::setw(5) << "LsrR";
	std::cout << std::left << std::setw(5) << "LrnS";
	std::cout << std::left << std::setw(5) << "LrnR";
	std::cout << std::left << std::setw(5) << "GerS";
	std::cout << std::left << std::setw(5) << "GerR";
	std::cout << std::left << std::setw(5) << "Scaled" << std::endl;
}

void UI::universityList(University uniArr[], int *currentIndex)
{

	const int pageSize = 20;
	int SIZE = 1422;
	int totalPages = (SIZE + pageSize - 1) / pageSize; // Calculate total number of pages

	// TODO
	if (SIZE == 0)
	{
		std::cout << "Dynamic Array is empty." << std::endl;
		return;
	}

	char userInput;
	do
	{
		clearScreen();
		std::cout << currentIndex << std::endl;
		universityHeader();
		// Display current page of data
		int start = *currentIndex;
		int end = std::min(*currentIndex + pageSize, SIZE);

		for (int i = start; i < end; i++)
		{
			std::cout << uniArr[i] << " ";
		}
		std::cout << std::endl;

		// Prompt user for navigation input
		std::cout << "Page " << (*currentIndex / pageSize) + 1 << " of " << totalPages << std::endl;
		std::cout << "Enter 'n' for next page, 'p' for previous page, or any other key to exit: ";
		std::cin >> userInput;

		// Handle user input for navigation
		if (userInput == 'n')
		{
			if (*currentIndex + pageSize < SIZE)
				*currentIndex += pageSize;
		}
		else if (userInput == 'p')
		{
			if (*currentIndex - pageSize >= 0)
				*currentIndex -= pageSize;
		}
		// Ignore any other input and exit the loop
	} while (userInput == 'n' || userInput == 'p');

	if (userInput != 'n' && userInput != 'p')
	{
		std::cout << "Returning to main menu..." << std::endl;
	}
}

// FEEDBACK MENUS
void UI::invalidOptionMsg()
{
	std::cout << "Invalid option! Please try again.\n";
}

void UI::clearScreen()
{
	std::cout << std::string(100, '\n');
	system("cls");
}

void UI::favouriteMenu()
{
	std::cout << "\nFavourite University Menu\n";
	std::cout << "1. View Favourite Universities\n";
	std::cout << "2. Add University to Favourites\n";
	std::cout << "3. Remove University from Favourites\n";
	std::cout << "4. Return to user menu\n";
	std::cout << "5. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::modifyUserMenu() {
    std::cout << "\nModify User Menu\n";
    std::cout << "1. Modify username\n";
    std::cout << "2. Modify password\n";
    std::cout << "3. Return to admin menu\n";
    std::cout << "4. Exit program\n";
    std::cout << "Enter your choice: ";
}
