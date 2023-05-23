#include "../include/UI.h"

#include <iostream>

void UI::mainMenu()
{
	std::cout << "Welcome to our SURS!\n";
	std::cout << "\nMain Menu\n";
	std::cout << "1. Display all universities' information\n";
	std::cout << "2. Sort universities by name\n";
	std::cout << "3. Search university details\n";
	std::cout << "4. Register as customer\n";
	std::cout << "5. Login as registered customer\n";
	std::cout << "0. Exit program\n";
	std::cout << "Enter your choice: ";
}