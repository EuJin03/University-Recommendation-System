// #ifndef USER_H
// #define USER_H

// #include <string>
// #include <ctime>

// struct userCredential
// {
// 	std::string password;
// 	tm *lastLogin;
// };

// class User
// {
// public:
// 	User(const std::string &username, const std::string &password);

// 	bool checkPassword(const std::string &password) const;
// 	void updateLastLogin();
// 	bool inactivityStatus() const;
// 	std::string getLastLogin() const;

// private:
// 	std::string username;
// 	std::string password;
// 	std::time_t lastLogin;
// };

// #endif

#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
class User
{
private:
	std::string username;
	std::string password;
	std::time_t lastLogin;
	// LinkedList<University> favUnivList;

public:
    User(const std::string &username, const std::string &password, const std::time_t &lastLogin);
	User();

	const std::string &getUsername() const;
	const std::string &getPassword() const;
	const std::time_t &getLastLogin() const;

	void setLastLogin(std::time_t newLastLogin);

    bool operator==(const User &user) const;
    friend std::ostream &operator<<(std::ostream &os, const User &user);
};

std::ostream &operator<<(std::ostream &os, const User &user);

#endif // USER_H