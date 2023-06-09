	/*
	craeted by eujin & bryan
*/
#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include "../include/LinkedList.h"
#include "../include/University.h"

class User
{
private:
	std::string username;
	std::string password;
	std::time_t lastLogin;
	bool isAdmin;
	LinkedList<University> favUnivList;

public:
	// Constructor
	User(const std::string &username, const std::string &password, const std::time_t &lastLogin, const bool &isAdmin = false, const LinkedList<University> &favUnivList = LinkedList<University>());

	// Copy constructor
	User(const User &user);
	User() = default;

	const std::string &getUsername() const;
	const std::string &getPassword() const;
	const std::time_t &getLastLogin() const;
	const bool &getIsAdmin() const;
	const LinkedList<University> &getFavUnivList() const;

	void setLastLogin(std::time_t newLastLogin);
	void setAsAdmin();
	void setFavUnivList(LinkedList<University> newFavUnivList);
	void setUsername(const std::string &newUsername);
	void setPassword(const std::string &newPassword);

	bool isNull() const { return false; }
	bool validate(const User &user) const;

	// Below codes are referenced from Jason (2023)
	// APA Citation: Jason. (2023, March 8). Override output operator << inside class c++ to print std::vector. Retrieved from stackoverflow: https://stackoverflow.com/questions/75670540/override-output-operator-inside-class-c-to-print-stdvector
	bool operator==(const User &user);
	friend std::ostream &operator<<(std::ostream &os, const User &user);
};

#endif // USER_H