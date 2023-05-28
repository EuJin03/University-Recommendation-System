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

    T &get(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Invalid index");
        }
        return array[index];
    }

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

    void set(const University &element, int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Invalid index" << std::endl;
            return;
        }

        if (index >= capacity)
        {
            // Resize the array to accommodate the new element
            int newCapacity = index + 1;
            T *newArray = new T[newCapacity];

            // Copy the existing elements to the new array
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }

            // Delete the old array and update the pointers
            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }

        array[index] = element;
    }

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
    }

    // Count the occurrences of each element in the Dynamic Array
    void countOccurrences(DynamicArray<T> *arr, DynamicArray<int> *totalCount)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count = 1;
            for (int j = i + 1; j < size; j++)
            {
                if (array[i] == array[j])
                {
                    count++;
                    for (int k = j; k < size - 1; k++)
                    {
                        array[k] = array[k + 1];
                    }
                    size--;
                    j--;
                }
            }
            arr->append(array[i]);
            totalCount->append(count);
        }

        for (int i = 0; i < sizeof(totalCount) / sizeof(int); i++)
        {
            std::cout << arr->get(i) << " : " << totalCount->get(i) << std::endl;
        }
    }

    void show()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // UNIVERSITY_RECOMMENDATION_SYSTEM_DYNAMICARRAY_H
