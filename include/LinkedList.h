#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Feedback.h"

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
};

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

    void insertAtBeginning(U data)
    {
        // Insert in a way so that the tail will have the latest node.
        Node<U> *newNode = new Node<U>();
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

    bool insertAtEnd(U data)
    {
        // Insert in a way so that the tail will have the latest node.
        Node<U> *newNode;
        Node<U> *temp = head;
        newNode = new Node<U>();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (checkUnique(data))
        {
            if (head != nullptr)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = tail->next;
            }
            else
            {
                head = newNode;
                tail = newNode;
            }
            size++;
            return true;
        }
        else
        {
            std::cout << "Record already exists in the list!" << std::endl;
            return false;
        }
    }

    void pushAndPointEnd(U data)
    {
        Node<U> *newNode;
        newNode = new Node<U>();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr)

        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
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

    // Remove a University Item based on its rank from the LinkedList
    void removeItem(U data)
    {
        Node<U> *current = head;

        while (current != nullptr)
        {
            if (current->data == data)
            {
                if (current == head)
                {
                    removeAtBeginning();
                }
                else if (current == tail)
                {
                    removeAtEnd();
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    size--;
                }
                break;
            }
            else
            {
                std::cout << "Record does not exist in the list!" << std::endl;
            }
            current = current->next;
        }
    }

    // Update an item in the LinkedList
    void updateItem(U data, U newData)
    {
        Node<U> *current = head;

        while (current != nullptr)
        {
            if (current->data == data)
            {
                current->data = newData;
                break;
            }
            else
            {
                std::cout << "Record does not exist in the list!" << std::endl;
            }
            current = current->next;
        }
    }

    int getSize() const
    {
        return size;
    }

    bool checkUnique(U data)
    {
        Node<U> *current = head;

        while (current != nullptr)
        {
            if (current->data == data)
            {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    // Printings
    void show()
    {
        Node<U> *current = head;

        if (current == nullptr)
        {
            std::cout << "List is empty" << std::endl;
        }
        else
        {
            while (current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    Node<U> *getTail()
    {
        if (tail != nullptr)
            return tail;
        else
            throw std::runtime_error("Empty list");
    }

    Node<U> *navigateNodes(Node<U> *current, int action)
    {
        if (action == 0)
        {
            if (current->prev != nullptr)
                current = current->prev;
            else
                std::cout << "This is the leftmost node, go front!.\n\n";
        }

        if (action == 1)
        {
            if (current->next != NULL)
                current = current->next;
            else
                std::cout << "This is the rightmost node, go back!\n\n";
        }

        return current;
    }

private:
    Node<U> *head;
    Node<U> *tail;
    int size;
};

#endif // LINKEDLIST_H
