//
// Created by 2702b on 22/5/2023.
//

#ifndef UNIVERSITY_RECOMMENDATION_SYSTEM_DYNAMICARRAY_H
#define UNIVERSITY_RECOMMENDATION_SYSTEM_DYNAMICARRAY_H
#include <iostream>
#include "UI.h"

template <class T>
class DynamicArray
{
private:
    T *array;
    int size;
    int capacity;

public:
    int currentIndex = 0;
    // Constructor
    DynamicArray()
    {
        size = 0;
        capacity = 1;
        array = new T[capacity];
    };

    // Destructor
    ~DynamicArray()
    {
        delete[] array;
    };

    int getSize() const { return size; };

    int getCapacity() const { return capacity; };

    // Append T object at the end of the Dynamic Array
    void append(const T &element)
    {
        if (size == capacity)
        {
            growArray();
        }
        array[size] = element;
        size++;
    };

    // Remove the last element of the Dynamic Array
    void pop()
    {
        if (size > 0)
        {
            //            array[size - 1] = NULL;
            size--;
            if (size < capacity / 2)
            {
                shrinkArray();
            }
        }
    };

    // Insert T element at the specified index
    void insertAt(const T &element, int index)
    {
        if (index < 0 || index > size)
        {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        if (size == capacity)
        {
            growArray();
        }
        for (int i = size; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = element;
        size++;
    };

    // Remove T element from the Dynamic Array regardless of index
    void remove(const T &element)
    {
        int index = -1;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == element)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            std::cout << "Element not found" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        //        array[size - 1] = NULL;
        size--;
        if (size < capacity / 2)
        {
            shrinkArray();
        }
    };

    // Increase Dynamic Array capacity by 2
    void growArray()
    {
        capacity *= 2;
        T *newArray = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    };

    // Decrease Dynamic Array capacity by 2
    void shrinkArray()
    {
        capacity /= 2;
        T *newArray = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    };

    // Check if Dynamic Array is empty
    bool isEmpty()
    {
        return size == 0;
    };

    // Print elements in Dynamic Array
    void show(UI ui)
    {
        const int pageSize = 20;                           // Number of columns to display per page
        int totalPages = (size + pageSize - 1) / pageSize; // Calculate total number of pages

        if (isEmpty())
        {
            std::cout << "Dynamic Array is empty." << std::endl;
            return;
        }

        char userInput;
        do
        {
            std::system("clear");
            ui.clearScreen();
            ui.universityHeader();
            // Display current page of data
            int start = currentIndex;
            int end = std::min(currentIndex + pageSize, size);

            for (int i = start; i < end; i++)
            {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;

            // Prompt user for navigation input
            std::cout << "Page " << (currentIndex / pageSize) + 1 << " of " << totalPages << std::endl;
            std::cout << "Enter 'n' for next page, 'p' for previous page, or any other key to exit: ";
            std::cin >> userInput;

            // Handle user input for navigation
            if (userInput == 'n')
            {
                if (currentIndex + pageSize < size)
                    currentIndex += pageSize;
            }
            else if (userInput == 'p')
            {
                if (currentIndex - pageSize >= 0)
                    currentIndex -= pageSize;
            }
            // Ignore any other input and exit the loop
        } while (userInput == 'n' || userInput == 'p');
    }
};

#endif // UNIVERSITY_RECOMMENDATION_SYSTEM_DYNAMICARRAY_H
