// #include <iostream>
// #include "../include/LinkedList.h"

// template <class T>
// LinkedList<T>::LinkedList()
// {
//     head = nullptr;
//     tail = nullptr;
//     size = 0;
// }

// template <class T>
// void LinkedList<T>::insertAtBeginning(T data)
// {
//     Node<T> *newNode = new Node<T>;
//     newNode->data = T(data);
//     newNode->next = head;
//     newNode->prev = nullptr;

//     if (head != nullptr)
//     {
//         head->prev = newNode;
//     }
//     else
//     {
//         tail = newNode;
//     }

//     head = newNode;
//     size++;
// }

// template <class T>
// void LinkedList<T>::insertAtEnd(T data)
// {
//     Node<T> *newNode = new Node<T>;
//     newNode->university = T(data);
//     newNode->next = nullptr;
//     newNode->prev = tail;

//     if (tail != nullptr)
//     {
//         tail->next = newNode;
//     }
//     else
//     {
//         head = newNode;
//     }

//     tail = newNode;
//     size++;
// }

// template <class T>
// void LinkedList<T>::removeAtBeginning()
// {
//     if (head != nullptr)
//     {
//         Node<T> *temp = head;
//         head = head->next;

//         if (head != nullptr)
//         {
//             head->prev = nullptr;
//         }
//         else
//         {
//             tail = nullptr;
//         }

//         delete temp;
//         size--;
//     }
// }

// template <class T>
// void LinkedList<T>::removeAtEnd()
// {
//     if (tail != nullptr)
//     {
//         Node<T> *temp = tail;
//         tail = tail->prev;

//         if (tail != nullptr)
//         {
//             tail->next = nullptr;
//         }
//         else
//         {
//             head = nullptr;
//         }

//         delete temp;
//         size--;
//     }
// }

// template <class T>
// void LinkedList<T>::quickSort(std::string username)
// {
//     // TODO: Bryan write out the quickSort algorithm
// } 

// template <class T>
// void LinkedList<T>::countingSort(std::string username)
// {
//     // TODO: Eugene write out the countingSort algorithm
// }

// template <class T>
// void LinkedList<T>::linearSearch()
// {
//     // TODO: Wen Xuen write out the linearSearch algorithm
// }

// template <class T>
// void LinkedList<T>::binarySearch()
// {
//     // TODO: Pin Cheng write out the binarySearch algorithm
// }

// template <class T>
// int LinkedList<T>::getSize() const
// {
//     return size;
// }

// template <class T>
// void LinkedList<T>::show()
// {
//     Node<T> *current = head;

//     while (current != nullptr)
//     {
//         std::cout << current->data.printFeedback() << std::endl;
//         current = current->next;
//     }
// }