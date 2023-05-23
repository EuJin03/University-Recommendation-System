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

    void quickSort(std::string username){
        // TODO: Bryan's Algo
    };
    void countingSort(std::vector<University> &arr)
    {
        if (arr.empty())
            return;

        // Find the maximum value of scoreScaled
        int maxScoreScaled = arr[0].scoreScaled;
        for (const auto &uni : arr)
        {
            if (uni.scoreScaled > maxScoreScaled)
                maxScoreScaled = uni.scoreScaled;
        }

        // Create a count array and initialize with 0
        std::vector<int> count(maxScoreScaled + 1, 0);

        // Count the occurrences of each scoreScaled value
        for (const auto &uni : arr)
        {
            count[uni.scoreScaled]++;
        }

        // Compute cumulative sums
        for (int i = 1; i <= maxScoreScaled; i++)
        {
            count[i] += count[i - 1];
        }

        // Create a temporary array to store sorted universities
        std::vector<University> sortedArr(arr.size());

        // Build the sorted array by iterating in reverse order
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            sortedArr[count[arr[i].scoreScaled] - 1] = arr[i];
            count[arr[i].scoreScaled]--;
        }

        // Update the original array with the sorted values
        std::copy(sortedArr.begin(), sortedArr.end(), arr.begin());
    };
    void linearSearch(){
        // TODO: Wen Xuen's Algo
    };
    void binarySearch(){
        // TODO: Pin Cheng's ALgo
    };
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

private:
    Node<U> *head;
    Node<U> *tail;
    int size;
};