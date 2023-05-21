#include <iostream>
#include "LL.h"
#include "Feedback.h"

FeedbackList::FeedbackList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void FeedbackList::insertAtBeginning(Feedback feedback)
{
    FeedbackNode *newNode = new FeedbackNode;
    newNode->feedback = Feedback(feedback);
    newNode->next = head;
    newNode->prev = nullptr;
    
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    else
    {
        tail = newNode;
    }
    
    head = newNode;
    size++;
}

void FeedbackList::show()
{
    FeedbackNode *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->feedback << std::endl;
        temp = temp->next;
    }
}