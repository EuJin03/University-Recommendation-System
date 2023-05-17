#include <iostream>
#include "University.h"

struct UniNode {
    University university;
    UniNode *next;
    UniNode *prev;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insertAtBeginning(University university);
    void insertAtEnd(University university);
    void quickSort(std::string username);
    void countingSort(std::string username);
    void linearSearch();
    void binarySearch();
    int getSize() const;

    // Printings
    void printUniversitiesInfo();
};