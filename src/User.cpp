#include "../include/User.h"
#include <iostream>

User::User(const std::string &username, const std::string &password, const std::time_t &lastLogin, const bool &isAdmin, const LinkedList<University> &favUnivList)
    : username(username), password(password), lastLogin(lastLogin), isAdmin(isAdmin), favUnivList(favUnivList) {}

User::User(const User &user) {
    this->username = user.getUsername();
    this->password = user.getPassword();
    this->lastLogin = user.getLastLogin();
    this->isAdmin = user.getIsAdmin();
    this->favUnivList = user.getFavUnivList();
}

User::User()
{
    this->username = "";
    this->password = "";
    this->lastLogin = 0;
    this->isAdmin = false;
    this->favUnivList = LinkedList<University>();
}

const std::string &User::getUsername() const
{
    return username;
}

const std::string &User::getPassword() const
{
    return password;
}

const std::time_t &User::getLastLogin() const
{
    return lastLogin;
}

const bool &User::getIsAdmin() const
{
    return isAdmin;
}

const LinkedList<University> &User::getFavUnivList() const
{
    return favUnivList;
}

void User::setLastLogin(std::time_t newLastLogin)
{
    lastLogin = newLastLogin;
}

void User::setAsAdmin()
{
    isAdmin = !isAdmin;
}

std::ostream &
operator<<(std::ostream &os, const User &user)
{
    os << "Username: " << user.username << std::endl;
    os << "Password: " << user.password << std::endl;
    os << "Last Login: " << user.lastLogin << std::endl;
    return os;
}

bool User::validate(const User &user) const
{
    return username == user.getUsername() && password == user.getPassword();
}

bool User::operator==(const User &user) {
    return username == user.getUsername() && password == user.getPassword();
}

// Update specific user's lastLogin field
void updateUserLastLogin(User &user)
{
    user.setLastLogin(std::time(nullptr));
}