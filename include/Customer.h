#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <ctime>

struct UserAccount
{
	std::string username;
	std::string password;
	tm *lastActive;
};
class Customer
{
public:
	Customer(const std::string &name);

private:
};

#endif // ADMIN_H