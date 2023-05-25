#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../include/User.h"
#include "../include/University.h"
#include "../include/Algorithms.h"
#include "../include/Feedback.h"
#include "../include/LinkedList.h"
#include "../include/HashTable.h"
#include <iostream>
#include <stdlib.h>

class Controller
{
public:
    // general
    std::string validate(std::string username, std::string password);

    // Unregistered user

    // Registered user
    void userController(University universityList[], int *univIndex, UI ui, LinkedList<Feedback> feedbackList, User currentUser);
    void feedbackController(LinkedList<Feedback> feedbackList, UI ui, User currentUser);

    // Admin
    void adminController();

    // Feedback insertFeedback(LinkedList<Feedback> feedbackList, std::string userFeedback);
    // void insertFavUni(std::string uniName);
    // checkExecutionTime(Algorithms algorithm, Algorithms::SortType sortType, std::vector<University> &uniArr);
};

#endif // CONTROLLER_H