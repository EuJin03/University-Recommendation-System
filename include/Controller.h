/*
    Created by eujin
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../include/User.h"
#include "../include/University.h"
#include "../include/Algorithms.h"
#include "../include/Feedback.h"
#include "../include/LinkedList.h"
#include "../include/HashTable.h"
#include "../include/DynamicArray.h"
#include "../include/UI.h"
#include <iostream>
#include <stdlib.h>
#include <limits>

class Controller
{
public:
    // general
    std::string validate(std::string username, std::string password);

    // Unregistered user
    bool registerUser(std::string username, std::string password, HashTable *userTable);
    void sort(University universityList[], int SIZE, Algorithms algorithms, Algorithms::SortType sortType, int choice, bool reverse);
    // Registered user
    void userController(HashTable *customer, University universityList[], int *univIndex, int SIZE, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> *feedbackList, User currentUser);
    void sortController(University universityList[], int *univIndex, int SIZE, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> *feedbackList, User currentUser);
    void searchController(University universityList[], int *univIndex, int SIZE, UI ui, User *favUser, DynamicArray<University> *top10, LinkedList<Feedback> *feedbackList, User currentUser);
    void favouriteController(HashTable *customer, User *currentUser, UI ui, University universityList[], int *univIndex, DynamicArray<University> *top10);
    void feedbackController(LinkedList<Feedback> *feedbackList, UI ui, User currentUser);

    // Admin
    void adminController(UI ui, University universityList[], int *univIndex, HashTable *customer,
                         LinkedList<Feedback> *feedbackList, User currentUser, DynamicArray<University> *top10);

    void modifyController(UI ui, HashTable *customer);

    void top10Controller(DynamicArray<University> *top10, UI ui);

    // void searchInt(University universityList[], int size, Algorithms algorithms, std::string searchCriteria, int choice,
    //                int searchCriteriaInt);

    // Feedback insertFeedback(LinkedList<Feedback> feedbackList, std::string userFeedback);
    // void insertFavUni(std::string uniName);
    // checkExecutionTime(Algorithms algorithm, Algorithms::SortType sortType, std::vector<University> &uniArr);
};

#endif // CONTROLLER_Hs