#include <iostream>
#include "Feedback.h"

struct FeedbackNode
{
    Feedback feedback;
    FeedbackNode *next;
    FeedbackNode *prev;
};

class FeedbackList
{
    public:
        FeedbackList();
        void insertAtBeginning(Feedback feedback);
        void show();
    
    private:
        FeedbackNode *head;
        FeedbackNode *tail;
        int size;
};