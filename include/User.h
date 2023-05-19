#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>

struct userCredential
{
	std::string password;
	tm *lastLogin;
};

class User
{
public:
	User(const std::string &username, const std::string &password);

	bool checkPassword(const std::string &password) const;
	void updateLastLogin();
	bool inactivityStatus() const;
	std::string getLastLogin() const;

private:
	std::string username;
	std::string password;
	std::time_t lastLogin;
};

#endif