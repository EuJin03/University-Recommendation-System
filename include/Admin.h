#ifndef ADMIN_H
#define ADMIN_H

#include <unordered_map>
#include "User.h"

class Admin
{
private:
	std::unordered_map<std::string, User> userMap;

public:
	void addAdmin(const User &user);
	User *getAdmin(const std::string &username);

	bool verifyAdmin(const std::string &username, const std::string &password) const;
};

#endif // ADMIN_H