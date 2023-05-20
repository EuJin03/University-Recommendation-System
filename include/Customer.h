#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <ctime>
#include "University.h"

struct UserAccount
{
	int customerIndex;
	std::string username;
	std::string password;
	std::string email;
	std::string contact;
	std::string dateOfBirth;
	University savedUniversities;
	tm *lastActive;

	UserAccount *prev;
	UserAccount *next;


//=====================
//For logged in users
//=====================

	// Login and logout
	void login(std::string username, std::string password);
	void logout();

	// save university
	void saveUniversity(std::string university);

	// feedback
	// void sendFeedback(Feedback feedback);
	void viewFeedback();

	
};

class Customer
{
public:
	Customer();
	~Customer();
	void addCustomerAtStart(std::string username, std::string password, std::string email, std::string contact, std::string dateOfBirth);
	void addCustomerAtEnd(std::string username, std::string password, std::string email, std::string contact, std::string dateOfBirth);
	int getSize() const;
	int getCustomerIndex(UserAccount *curr);
	std::string getUsername(UserAccount *curr);
	std::string getPassword(UserAccount *curr);
	std::string getEmail(UserAccount *curr);
	std::string getContact(UserAccount *curr);
	std::string getDateOfBirth(UserAccount *curr);
	University getSavedUniversities(UserAccount *curr);
	tm *getLastActive(UserAccount *curr);
	
//=====================
//For all users
//=====================

	// Printings
	void printCustomersInfo();

	// register
	void registerAccount(std::string username, std::string password);

private:
	UserAccount *head;
	UserAccount *tail;
	int size;
	int customerIndex;
};

#endif // CUSTOMER_H