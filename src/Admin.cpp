// #include "../include/Admin.h"

// void Admin::addAdmin(const User &user)
// {
// 	userMap[user.getUsername()] = user;
// }

// User *Admin::getAdmin(const std::string &username)
// {
// 	if (userMap.count(username))
// 	{
// 		return &userMap[username];
// 	}
// 	return nullptr;
// }

// bool Admin::verifyAdmin(const std::string &username, const std::string &password) const
// {
// 	auto it = userMap.find(username);
// 	if (it != userMap.end() && it->second.getPassword() == password)
// 	{
// 		return true;
// 	}
// 	return false;
// }