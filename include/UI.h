#ifndef UI_H
#define UI_H

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

	// user login/register menu
	void loginMenu();
	void registerMenu();

	// feedback menu

	// favourite list menu

	// table ui
	void
	universityHeader();

	// interactive commands/outputs
	void inputErrorMsg();
	void invalidOptionMsg();

	// helper & utility methods
	void clearScreen();
};

#endif