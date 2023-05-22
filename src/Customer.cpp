#include <iostream>
#include <algorithm>
#include "../include/Customer.h"

Customer::Customer(int tableSize)
{
	hashTable.reserve(tableSize);
}

void Customer::addCustomer(const User &user)
{
	std::size_t hashValue = hasher(user.getUsername());
	std::size_t index = hashValue % hashTable.size();
	hashTable[index].push_back(user);
}

void Customer::removeCustomer(const std::string &username)
{
	std::size_t hashValue = hasher(username);
	std::size_t index = hashValue % hashTable.size();
	auto &userList = hashTable[index];

	for (auto it = userList.begin(); it != userList.end(); ++it)
	{
		if (it->getUsername() == username)
		{
			userList.erase(it);
			break;
		}
	}
}

bool Customer::verifyCustomer(const std::string &username, const std::string &password) const
{
	int index = hasher(username) % hashTable.size();
	for (const auto &user : hashTable[index])
	{
		if (user.getUsername() == username && user.getPassword() == password)
			return true;
	}
	return false;
}

bool Customer::updateLastLogin(const std::string &username)
{
	int index = hasher(username) % hashTable.size();
	for (auto &user : hashTable[index])
	{
		if (user.getUsername() == username)
		{
			user.setLastLogin(std::time(nullptr));
			return true;
		}
	}
	return false;
}

void Customer::printCustomerDetails(const std::string &username)
{
	int index = hasher(username) % hashTable.size();
	for (const auto &user : hashTable[index])
	{
		if (user.getUsername() == username)
		{
			std::cout << "Username: " << user.getUsername() << "\n";
			std::cout << "Last Login: " << std::ctime(&user.getLastLogin()) << "\n";
			return;
		}
	}
	std::cout << "No such user exists.\n";
}

bool Customer::deleteInactiveAccounts()
{
	bool accountsDeleted = false;
	std::time_t currentTime = std::time(nullptr);
	for (auto &bucket : hashTable)
	{
		auto itr = std::remove_if(bucket.begin(), bucket.end(),
															[currentTime](const User &user)
															{ return currentTime - user.getLastLogin() > 60 * 60 * 24 * 30; });
		if (itr != bucket.end())
		{
			bucket.erase(itr, bucket.end());
			accountsDeleted = true;
		}
	}
	return accountsDeleted;
}

void Customer::printAllUsersDetails()
{
	for (const auto &userList : hashTable)
	{
		for (const User &user : userList)
		{
			std::cout << "Username: " << user.getUsername() << std::endl;
			std::cout << "Password: " << user.getPassword() << std::endl;

			std::tm *lastLoginTime = std::localtime(&user.getLastLogin());
			char buffer[80];
			std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", lastLoginTime);

			std::cout << "Last Login: " << buffer << std::endl;
			std::cout << std::endl;
		}
	}
}