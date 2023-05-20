#include <iostream>
#include <iomanip>
#include "../include/Customer.h"

using namespace std;

void printCustomerHeader();
void printCustomer(UserAccount *curr);

Customer::Customer()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
    this->customerIndex = 1;
}

Customer::~Customer()
{
    // Clean up linked list
    UserAccount *current = head;
    while (current != nullptr)
    {
        UserAccount *temp = current;
        current = current->next;
        delete temp;
    }
}

void Customer::addCustomerAtStart(std::string username, std::string password, std::string email, std::string contact, std::string dateOfBirth)
{
    UserAccount *newNode = new UserAccount;
    newNode->customerIndex = this->customerIndex;
    newNode->username = username;
    newNode->password = password;
    newNode->email = email;
    newNode->contact = contact;
    newNode->dateOfBirth = dateOfBirth;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    size++;
    this->customerIndex++;
}

void Customer::addCustomerAtEnd(std::string username, std::string password, std::string email, std::string contact, std::string dateOfBirth)
{
    if (tail == nullptr)
	{
		addCustomerAtStart(username, password, email, contact, dateOfBirth);
	}
    else
    {
        UserAccount *newNode = new UserAccount;
        newNode->customerIndex = this->customerIndex;
        newNode->username = username;
        newNode->password = password;
        newNode->email = email;
        newNode->contact = contact;
        newNode->dateOfBirth = dateOfBirth;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
        this->customerIndex++;
    }
}

int Customer::getSize() const
{
    return size;
}

int Customer::getCustomerIndex(UserAccount *curr)
{
    return customerIndex;
}

std::string Customer::getUsername(UserAccount *curr)
{
    return curr->username;
}

std::string Customer::getPassword(UserAccount *curr)
{
    return curr->password;
}

std::string Customer::getEmail(UserAccount *curr)
{
    return curr->email;
}

std::string Customer::getContact(UserAccount *curr)
{
    return curr->contact;
}

std::string Customer::getDateOfBirth(UserAccount *curr)
{
    return curr->dateOfBirth;
}

University Customer::getSavedUniversities(UserAccount *curr)
{
    return curr->savedUniversities;
}

tm *Customer::getLastActive(UserAccount *curr)
{
    return curr->lastActive;
}


void Customer::printCustomersInfo()
{
    UserAccount *curr = head;
    int count = 1;
    while (curr != nullptr)
    {
        printCustomerHeader();
        while (count < 20)
        {
            // std::cout << curr->customerIndex << std::endl;
            // std::cout << curr->username << std::endl;
			// std::cout << curr->password << std::endl;
            // std::cout << curr->email << std::endl;
            // std::cout << curr->contact << std::endl;
            // std::cout << curr->dateOfBirth << std::endl;
            // std::cout << curr->lastActive << std::endl;
            // std::cout << std::endl;
            printCustomer(curr);
			curr = curr->next;
			count++;
        }
    }
}

void printCustomerHeader()
{
    cout    << setw(8) << left << "Index"
            << setw(30) << left << "Username"
            << setw(20) << left << "Password"
            << setw(30) << left << "Email"
            << setw(15) << left << "Contact"
            << setw(15) << left << "Date Of Birth"
            << setw(15) << left << "Last Active"
            << endl;

    cout    << setw(8) << left << string(7, '=')
            << setw(30) << left << string(29, '=')
            << setw(20) << left << string(19, '=')
            << setw(30) << left << string(29, '=')
            << setw(15) << left << string(14, '=')
            << setw(15) << left << string(14, '=')
            << setw(15) << left << string(14, '=')
            << endl;
}

void printCustomer(UserAccount *curr)
{
    cout    << setw(8) << left << curr->customerIndex
            << setw(30) << left << curr->username
            << setw(20) << left << curr->password
            << setw(30) << left << curr->email
            << setw(15) << left << curr->contact
            << setw(15) << left << curr->dateOfBirth
            << setw(15) << left << curr->lastActive
            << endl;
    cout << endl;
}