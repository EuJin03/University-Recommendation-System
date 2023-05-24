#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../include/User.h"
#include "../include/University.h"
#include "../include/Algorithms.h"
#include "../include/Feedback.h"
#include "../include/LinkedList.h"
#include <iostream>

class Controller
{
public:
    std::string validate(std::string username, std::string password);
    User login(std::string username, std::string password);
    User registerUser();
    Feedback insertFeedback(LinkedList<Feedback> feedbackList, std::string userFeedback);
    void insertFavUni(std::string uniName);
    long long checkExecutionTime(Algorithms algorithm, Algorithms::SortType sortType, std::vector<University> &uniArr);
};

#endif // CONTROLLER_H