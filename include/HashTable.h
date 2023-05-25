#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

#include "User.h"

class HashTable
{
private:
	std::vector<std::list<User>> hashTable;
	std::hash<std::string> hasher;

public:
	HashTable(int tableSize);

	void addUser(const User &user);
	void removeUser(const std::string &username);
	User getUser(const std::string &username);

	// TODO: implement these
	bool verifyUser(const std::string &username, const std::string &password) const;
	bool updateLastLogin(const std::string &username);
	void printUserDetails(const std::string &username);
	void printAllUsersDetails();
	bool deleteInactiveAccounts();
	bool validateUsername(const std::string &username) const;
};

#endif // HASHTABLE_H
