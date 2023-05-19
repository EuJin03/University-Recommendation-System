#include <iostream>
#include "University.h"
#include "Feedback.h"

template <class T>
struct Node 
{
    T data;
    Node<T> *next;
    Node<T> *prev;

};

// struct UniNode
// {
//     University university;
//     UniNode *next;
//     UniNode *prev;
// };

// struct FeedbackNode
// {
//     Feedback feedback;
//     FeedbackNode *next;
//     FeedbackNode *prev;
// }

template <class U>
class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    // ~LinkedList();
    
    void insertAtBeginning(U data)
    {
        Node<U> *newNode = new Node<U>;
        newNode->data = data;
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

    void insertAtEnd(U data)
    {
        Node<U> *newNode = new Node<U>;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        
        if (tail != nullptr)
        {
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }
        
        tail = newNode;
        size++;
    }

    void removeAtBeginning()
    {
        if (head != nullptr)
        {
            Node<U> *temp = head;
            head = head->next;
            
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            
            delete temp;
            size--;
        }
    }

    void removeAtEnd() 
    {
        if (tail != nullptr)
        {
            Node<U> *temp = tail;
            tail = tail->prev;
            
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            
            delete temp;
            size--;
        }
    }

    void quickSort(std::string username);
    void countingSort(std::string username);
    void linearSearch();
    void binarySearch();
    int getSize() const
    {
        return size;
    }

    // Printings
    void show()
    {
        Node<U> *current = head;
        
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        
        std::cout << std::endl;
    }

private:
    Node<U> *head;
    Node<U> *tail;
    int size;
};