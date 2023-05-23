//
// Created by 2702b on 23/5/2023.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include "../include/University.h"

class Algorithms
{
public:
    // Quick Sort Algorithm
    void swap(University *uniA, University *uniB);
    int partition(University *uniArr, int start, int pivot, bool registered, int choice);
    void quickSort(University *uniArr, int start, int end, bool registered, int choice);

    // Counting Sort Algorithm
    void countingSort(University *uniArr, int size, int exp);

    // Linear Search Algorithm
    int linearSearch(University *uniArr, int size, std::string key);

    // Binary Search Algorithm
    int binarySearch(University *uniArr, int start, int end, std::string key);
};

#endif //UNIVERSITY_RECOMMENDATION_SYSTEM_ALGORITHMS_H