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
        AR_SCORE = 1,
        FSR_SCORE = 2,
        ER_SCORE = 3
    };

    // Quick Sort Algorithm
    void swap(University *uniA, University *uniB);
    int partition(University *uniArr, int start, int pivot, bool registered, int choice);
    void quickSort(University *uniArr, int start, int end, bool registered, int choice);

    // Counting Sort Algorithm
    static DynamicArray<University> countSort(DynamicArray<University> &uniArr, SortType sortType);
    static int getMaxScore(DynamicArray<University> &uniArr, SortType sortType);
    static int getScore(University &uni, SortType sortType);

    // Linear Search Algorithm
    int linearSearch(University *uniArr, int size, std::string key);

    // Binary Search Algorithm
    int binarySearch(University *uniArr, int start, int end, std::string key);
};

#endif // UNIVERSITY_RECOMMENDATION_SYSTEM_ALGORITHMS_H