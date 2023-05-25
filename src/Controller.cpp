#include "../include/Controller.h"

std::string Controller::validate(std::string username, std::string password)
{
    if (username.length() < 6)
    {
        return "Username must be at least 6 characters long";
    }
    else if (password.length() < 6)
    {
        return "Password must be at least 6 characters long";
    }
    else
    {
        return "success";
    }
}

User Controller::login(HashTable userTable, std::string username, std::string password)
{
    User user = NullUser();
    if (userTable.verifyUser(username, password))
    {
        std::cout << "Login successful!" << std::endl;
        return userTable.getUser(username);
//        return username;
    }
    else
    {
        std::cout << "Invalid username or password!" << std::endl;
    }
    return user;
//    return "";
}