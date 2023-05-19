#include <iostream>
#include <string>

#include "../include/User.h"

User::User(const std::string &username, const std::string &password)
		: username(username), password(password), lastLogin(std::time(nullptr)) {}

bool User::checkPassword(const std::string &password) const
{
	return this->password == password;
}

void User::updateLastLogin()
{
	lastLogin = time(0);
}
bool User::inactivityStatus() const
{
	// Need to get the current user from the array first
	std::time_t currentTime = std::time(nullptr);
	return lastLogin < currentTime;
}

std::string User::getLastLogin() const
{
	// Need to get the current user from the array first
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%y-%m-%d %H:%M:%S", localtime(&lastLogin));
	return buffer;
}
