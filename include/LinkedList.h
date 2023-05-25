#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

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

    bool insertAtEnd(U data)
    {
        Node<U> *newNode;
        Node<U> *temp = head;
        newNode = new Node<U>();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (checkUnique(data))
        {
            if (head != nullptr) {
                tail->next = newNode;a
                newNode->prev = tail;
                tail = tail->next;
            } else {
                head = newNode;
                tail = newNode;
            }

            tail = newNode;
            size++;
            return true;
        } else {
            std::cout << "Record already exists in the list!" << std::endl;
            return false;
        }
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
            } else {
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

private:
    Node<U> *head;
    Node<U> *tail;
    int size;
};

#endif // LINKEDLIST_H