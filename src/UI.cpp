#include "../include/UI.h"
#include <iostream>
#include <iomanip>

void UI::mainMenu()
{
	std::cout << "Welcome to SURS!\n";
	std::cout << "\nMain Menu\n";
	std::cout << "1. Display all universities' information\n";
	std::cout << "2. Sort universities by name\n";
	std::cout << "3. Search university details\n";
	std::cout << "4. Register as customer\n";
	std::cout << "5. Login as registered customer\n";
	std::cout << "0. Exit program\n";
	std::cout << "Enter your choice: ";
}

void UI::customerMenu()
{
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
	std::cout << "\nAdmin Menu\n";
	std::cout << "1. Display all universities' information\n";
	std::cout << "2. Sort universities\n";
	std::cout << "3. Search university details\n";
	std::cout << "4. Display feedback\n";
	std::cout << "5. Logout\n";
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

void UI::clearScreen()
{
	std::cout << std::string(100, '\n');
}