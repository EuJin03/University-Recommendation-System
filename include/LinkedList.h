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
        size++;
    }

    void insertAtEnd(U data)
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

    U getTail()
    {
        if (tail != nullptr)
            return tail->data;
        else
            throw std::runtime_error("Empty list");
    }

    Node<U> navigateNodes(Node<U> current, int action)
    {
        if (action == 0)
        {
            if (current->prev != NULL)
                current = current->prev;
            else
                std::cout << "This is the leftmost node, go front!.\n";
        }

        if (action == 1)
        {
            if (current->next != NULL)
                current = current->next;
            else
                std::cout << "This is the leftmost node, go back!\n";
        }

        return current;
    }

private:
    Node<U> *head;
    Node<U> *tail;
    int size;
};

#endif // LINKEDLIST_H
