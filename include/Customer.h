#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <ctime>
#include <vector>
#include <list>

#include "User.h"

class Customer
{
private:
	std::vector<std::list<User>> hashTable;
	std::hash<std::string> hasher;

public:
	Customer(int tableSize);

	void addCustomer(const User &user);
	void removeCustomer(const std::string &username);

	// TODO: implement these
	bool verifyCustomer(const std::string &username, const std::string &password) const;
	bool updateLastLogin(const std::string &username);

	void printCustomerDetails(const std::string &username);
	void printAllUsersDetails();
	bool deleteInactiveAccounts();
};

#endif // CUSTOMER_H
