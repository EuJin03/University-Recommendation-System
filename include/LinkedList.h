#include <iostream>
#include "University.h"

struct UniNode {
    University university;
    UniNode *next;
    UniNode *prev;
}

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insertAtBeginning(University university);
    void addUniversityAtEnd(University university);
    int getSize() const;

    // Printings
    void printUniversitiesInfo();
}