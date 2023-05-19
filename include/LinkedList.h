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
        Node<U> *newNode;
        newNode = new Node<U>();
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
        std::cout << "========= Node inserted =========" << std::endl;
        std::cout << std::endl;
        size++;
    }

    void insertAtEnd(U data)
    {
        Node<U> *newNode;
        newNode = new Node<U>();
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
        std::cout << "========= Node inserted =========" << std::endl;
        std::cout << std::endl;
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
            std::cout << "========= Node removed =========" << std::endl;
            std::cout << std::endl;
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
            std::cout << "========= Node removed =========" << std::endl;
            std::cout << std::endl;
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
        
        if (current == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        } else
        {
            while (current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

private:
    Node<U> *head;
    Node<U> *tail;
    int size;
};