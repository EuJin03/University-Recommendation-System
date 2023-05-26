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

User Controller::login(HashTable *customerTable, std::string username, std::string password)
{
    do
    {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
    } while (validate(username, password) != "success");
}

bool Controller::registerUser(HashTable *userTable)
{   
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::time_t lastLogin;
    bool isAdmin = false;
    if (validate(username, password) != "success")
    {
        return false;
    }
    else
    {
        User user(username, password, lastLogin, isAdmin);
        userTable->addUser(user);
    }
    return true;
}
