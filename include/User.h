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

	const std::string &getUsername() const;
	const std::string &getPassword() const;
	const std::time_t &getLastLogin() const;
	const bool &getIsAdmin() const;
	const LinkedList<University> &getFavUnivList() const;

	void setLastLogin(std::time_t newLastLogin);
	void setAsAdmin();

	bool validate(const User &user) const;
	bool operator==(const User &user);
	friend std::ostream &operator<<(std::ostream &os, const User &user);
};

std::ostream &operator<<(std::ostream &os, const User &user);

#endif // USER_H