/*
	craeted by eujin
*/
#ifndef UI_H
#define UI_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "University.h"

class UI
{
public:
	// main menu
	void mainMenu();
	void customerMenu();
	void adminMenu();

	// sort menu
	void guestSortMenu();
	void userSortMenu();

	// search menu
	void guestSearchMenu();
	void userSearchMenu();

	// feedback menu

	// modify user menu
	void modifyUserMenu();

	// favourite list menu
	void favouriteMenu();

	// university ui
	void universityHeader();
	void universityList(University *uniArr, int *currentIndex);

	// interactive commands/outputs
	void inputErrorMsg();
	void invalidOptionMsg();

	// helper & utility methods
	void clearScreen();
};

#endif