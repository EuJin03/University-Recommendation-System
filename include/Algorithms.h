//
// Created by 2702b on 23/5/2023.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include "../include/University.h"
#include "../include/DynamicArray.h"

class Algorithms
{
public:
    enum SortType
    {
        INSTITUTION = 0,
        AR_SCORE = 1,
        FSR_SCORE = 2,
        ER_SCORE = 3,
        RANK_SCORE = 4,
        AR_RANK_SORT = 5,
        FSR_RANK_SORT = 6,
        ER_RANK_SORT = 7
    };
    enum SearchType
    {
        RANK = 0,
        AR_RANK = 1,
        FSR_RANK = 2,
        ER_RANK = 3
    };

    //toLower function
    std::string toLower(std::string &str);


    // Quick Sort Algorithm
    void swap(University *uniA, University *uniB);
    int partition(University uniArr[], int start, int pivot, bool registered, int choice);
    void quickSort(University uniArr[], int start, int end, bool registered, int choice);

    // Counting Sort Algorithm
    static void countSort(University universityList[], int size, SortType sortType);
    static void countSortInteger(University universityList[], int size, SortType sortType);
    static void countSortString(University universityList[], int size, SortType sortType);
    static int getMaxScore(University universityList[], int size, SortType sortType);
    static int getScore(University uni, SortType sortType);
    static std::string getScoreString(University uni, SortType sortType);

    // Linear Search Algorithm
    void linearSearch(University universityList[], int size, int criteria, std::string key);

    // Binary Search Algorithm
    void binarySearch(University universityList[], int size, int rank);
    void binarySearchWithDuplicates(University universityList[], int size, int choice, int rank);
    int* getRank(University universityList[], int mid, int choice);
};

#endif // UNIVERSITY_RECOMMENDATION_SYSTEM_ALGORITHMS_H