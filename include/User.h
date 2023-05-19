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
private:
	std::string username;
	std::string password;
	tm *lastLogin;

public:
	void userRegister();
	void userLogin();
	void inactiveUser();
};

#endif