//
// Created by 2702b on 22/5/2023.
// Referenced from Geeks for Geeks
// APA citation: GeeksforGeeks. (2023, May 24). How do Dynamic Arrays work? Retrieved from Geeks for Geeks: https://www.geeksforgeeks.org/how-do-dynamic-arrays-work/
//

#ifndef UNIVERSITY_RECOMMENDATION_SYSTEM_DYNAMICARRAY_H
#define UNIVERSITY_RECOMMENDATION_SYSTEM_DYNAMICARRAY_H
#include <iostream>
#include "UI.h"

template <class T>
class DynamicArray {
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

    /**
     * @brief Returns the element at the specified index
     * @param index The index of the element to return
     * @return The element at the specified index
    */
    T get(int index)
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

    /**
     * @brief Inserts the specified element at the specified index
     * @param element The element to insert
     * @param index The index at which to insert the element
     * @return void
     * @throws std::out_of_range if the index is invalid
    */
    void set(T element, int index)
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

    /**
     * @brief Returns true if the array contains the specified element
     * @param data The element to search for
     * @return true if the array contains the specified element
     * @return false if the array does not contain the specified element
    */
    bool contains(T data) {
        // Return true if the array contains T data
        for (int i = 0; i < size; i++) {
            if (array[i] == data) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Returns the index of the specified element
     * @param data The element to search for
     * @return The index of the specified element
     * @return -1 if the element is not found
    */
    int find(T data) {
        for (int i = 0; i < size; i++) {
            if (array[i] == data) {
                return i;
            }
        }
        return -1;
    }

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

    /**
     * @brief Prints the elements of the Dynamic Array
     * @return void
    */
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
