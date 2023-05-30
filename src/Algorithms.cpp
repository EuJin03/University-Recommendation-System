#include <iostream>
#include <chrono>
#include "../include/Algorithms.h"
#include "../include/University.h"
#include "../include/UI.h"

#include <vector>

/**
 * @brief Quick Sort Algorithm -- swap function
 * @usage Swap 2 University objects in an array.
 *
 * @param uniA
 * @param uniB
 */
void Algorithms::swap(University *uniA, University *uniB)
{
    University temp = *uniA;
    *uniA = *uniB;
    *uniB = temp;
}

/**
 * @brief Quick Sort Algorithm -- partition function
 * @usage Partition the array into 2 parts, one with elements smaller than the pivot, and the other with elements
 * larger than the pivot.
 *
 * @param uniArr
 * @param start
 * @param end
 * @param registered
 *
 * Registered users can sort by Academic Reputation score (arScore), Faculty/Student Ratio score (fsrScore),
 * and Employer Reputation score (erScore).
 * Unregistered users can sort by Institution name only.
 */
int Algorithms::partition(University uniArr[], int start, int pivot, bool registered, int choice)
{
    int i = start - 1;
    if (registered)
    { // Registered users, need to think how to decide on which column to sort on.
        // TODO: Figure out how to decide which column to sort on.
        switch (choice)
        {
        case 0:
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getInstitution() < uniArr[pivot].getInstitution())
                {
                    i++;
                    swap(&uniArr[i], &uniArr[j]);
                }
            }
            break;
        case 1: // Academic Reputation score (arScore)
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getArScore() > uniArr[pivot].getArScore())
                {
                    i++;
                    swap(&uniArr[i], &uniArr[j]);
                }
            }
            break;
        case 2: // Faculty/Student Ratio score (fsrScore)
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getFsrScore() > uniArr[pivot].getFsrScore())
                {
                    i++;
                    swap(&uniArr[i], &uniArr[j]);
                }
            }
            break;
        case 3: // Employer Reputation score (erScore)
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getErScore() > uniArr[pivot].getErScore())
                {
                    i++;
                    swap(&uniArr[i], &uniArr[j]);
                }
            }
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        };
        swap(&uniArr[i + 1], &uniArr[pivot]);
        return i + 1;
    }
    else
    { // Unregistered users, sort by Institution name only.
        for (int j = start; j < pivot; j++)
        {
            if (uniArr[j].getInstitution() < uniArr[pivot].getInstitution())
            {
                i++;
                swap(&uniArr[i], &uniArr[j]);
            }
        }
        swap(&uniArr[i + 1], &uniArr[pivot]);
        return i + 1;
    }
}

/**
 * @brief Quick Sort Algorithm -- quickSort function
 * @usage Sort the array using the partition function, teh registered parameter is passed to partition to ensure
 * that the correct column is sorted on.
 *
 * @param uniArr
 * @param start
 * @param end
 * @param registered
 */
void Algorithms::quickSort(University uniArr[], int start, int end, bool registered, int choice)
{
    if (start < end)
    {
        int pivot = partition(uniArr, start, end, registered, choice);
        quickSort(uniArr, start, pivot - 1, registered, choice);
        quickSort(uniArr, pivot + 1, end, registered, choice);
    }
}

void Algorithms::countSort(University universityList[], int size, SortType sortType, bool reverse)
{
    if (sortType == INSTITUTION)
    {
        countSortString(universityList, size, sortType, reverse);
    }
    else
    {
        countSortInteger(universityList, size, sortType, reverse);
    }
}

/**
 * @brief Count Sort Algorithm.
 * @param uniArr array of University objects to be sorted.
 * @param sortType The type of sorting to be applied.
 * @param reverse Whether to sort in ascending or descending order.
 * @return The sorted array of University objects.
 * @ref https://www.geeksforgeeks.org/counting-sort/
 *
 * This function implements the Count Sort algorithm to sort the uniArr array. The sortType parameter is used
 * to determine the sorting criteria.
 */
void Algorithms::countSortInteger(University universityList[], int size, SortType sortType, bool reverse)
{
    int n = size;
    int maxScore = getMaxScore(universityList, size, sortType);

    University *output = new University[n];
    int *count = new int[maxScore + 1]();

    for (int i = 0; i < n; i++)
    {
        int score = getScore(universityList[i], sortType); // getScore returns the score based on the sortType parameter.
        count[score]++;                                    //  count[score] is the number of universities with score equal to score.
    }

    if (reverse)
    {
        for (int i = 1; i <= maxScore; i++)
        {
            count[i] += count[i - 1]; // count[i] is the number of universities with score less than or equal to i.
        }
    }
    else
    {
        for (int i = maxScore - 1; i >= 0; i--)
        {
            count[i] += count[i + 1]; // count[i] is the number of universities with score greater than or equal to i.
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int score = getScore(universityList[i], sortType);
        output[count[score] - 1] = universityList[i]; // output[count[score] - 1] is the position of the university in the sorted array.
        count[score]--;
    }

    for (int i = 0; i < n; i++)
    {
        universityList[i] = output[i]; // Copy the sorted array to the original array.
    }
    delete[] output; // Delete the temporary array.
    delete[] count;
}

void Algorithms::countSortString(University universityList[], int size, SortType sortType, bool reverse)
{
    int n = size;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int len = getScoreString(universityList[i], sortType).length(); // getScoreString returns the string based on the sortType parameter.
        maxLen = std::max(maxLen, len);                                 // maxLen is the length of the longest string.
    }

    int k = 128;

    University *output = new University[n];
    int *count = new int[k]();

    for (int len = maxLen; len > 0; len--)
    {
        for (int i = 0; i < k; i++)
            count[i] = 0; // count[i] is the number of universities with the last character of the string equal to i.

        // Count the number of universities with the last character of the string equal to i.
        for (int i = 0; i < n; i++)
        {
            std::string institution = getScoreString(universityList[i], sortType);
            if (institution.length() < len)
                count[0]++;
            else
                count[int(institution[len - 1])]++;
        }

        if (reverse)
        {
            for (int i = 1; i < k; i++)
                count[i] += count[i - 1]; // count[i] is the number of universities with the last character of the string less than or equal to i.
        }
        else
        {
            for (int i = k - 2; i >= 0; i--)
                count[i] += count[i + 1]; // count[i] is the number of universities with the last character of the string greater than or equal to i.
        }

        // output[count[i] - 1] is the position of the university in the sorted array.
        for (int i = n - 1; i >= 0; i--)
        {
            std::string institution = getScoreString(universityList[i], sortType);
            if (institution.length() < len)
            {
                output[count[0] - 1] = universityList[i]; // output[count[0] - 1] is the position of the university in the sorted array.
                count[0]--;
            }
            else
            {
                output[count[int(institution[len - 1])] - 1] = universityList[i]; // output[count[int(institution[len - 1])] - 1] is the position of the university in the sorted array.
                count[int(institution[len - 1])]--;                               // count[int(institution[len - 1])] is the number of universities with the last character of the string equal to institution[len - 1].
            }
        }

        for (int i = 0; i < n; i++)
        {
            universityList[i] = output[i];
        }
    }

    delete[] output;
    delete[] count;
}

/**
 * @brief Get the maximum score from a std::vector of University objects.
 * @param uniArr std::vector of University objects.
 * @param sortType The type of sorting to be applied.
 * @return The maximum score.
 *
 * This function iterates through the uniArr std::vector to find the maximum score based on the sortType parameter.
 */
int Algorithms::getMaxScore(University universityList[], int size, SortType sortType)
{
    int n = size;
    int maxScore = getScore(universityList[0], sortType);

    for (int i = 1; i < n; i++)
    {
        int score = getScore(universityList[i], sortType);
        if (score > maxScore)
        {
            maxScore = score;
        }
    }

    return maxScore;
}

/**
 * @brief Get the score of a University object based on the sort type.
 * @param uni University object.
 * @param sortType The type of sorting to be applied.
 * @return The score of the University object.
 *
 * This function returns the score of a University object based on the sortType parameter. It is used to determine
 * the score to be considered when sorting the universities.
 */
int Algorithms::getScore(University uni, SortType sortType)
{
    switch (sortType)
    {
    case AR_SCORE:
        return uni.getArScore();
    case FSR_SCORE:
        return uni.getFsrScore();
    case ER_SCORE:
        return uni.getErScore();
    case RANK_SCORE:
        return uni.getRank();
    case AR_RANK_SORT:
        return uni.getArRank();
    case FSR_RANK_SORT:
        return uni.getFsrRank();
    case ER_RANK_SORT:
        return uni.getErRank();
    default:
        return -1;
    }
}

std::string Algorithms::getScoreString(University uni, SortType sortType)
{
    if (sortType == INSTITUTION)
        return uni.getInstitution();
    else
        return "";
}

std::string Algorithms::toLower(std::string &str)
{
    for (auto &c : str)
    {
        c = tolower(c);
    }
    return str;
}

long long Algorithms::linearSearch(University universityList[], int size, int criteria, std::string key, int rank)
{
    UI ui;
    // int rank;
    std::string locale;
    bool found = false;
    long long duration;
    auto linearStartLoad = std::chrono::high_resolution_clock::now();
    switch (criteria)
    {
    case 1:
        ui.universityHeader();
        linearStartLoad = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < size; i++)
        {
            key = toLower(key);
            std::string uniName = universityList[i].getInstitution();
            uniName = toLower(uniName);
            if (uniName.find(key) != std::string::npos)
            {

                if (!found)
                {
                    found = true;
                    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - linearStartLoad).count();
                }
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;
    case 2:
        ui.universityHeader();
        linearStartLoad = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < size; i++)
        {
            key = toLower(key);
            std::string locale = universityList[i].getLocale();
            locale = toLower(locale);
            if (locale.find(key) != std::string::npos)
            {

                if (!found)
                {
                    found = true;
                    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - linearStartLoad).count();
                }
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;
    case 3:
        ui.universityHeader();
        linearStartLoad = std::chrono::high_resolution_clock::now();
        // rank = std::stoi(key);
        // std::cout << rank << std::endl;
        for (int i = 0; i < size; i++)
        {
            if (universityList[i].getRank() == rank)
            {
                if (!found)
                {
                    found = true;
                    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - linearStartLoad).count();
                }
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;

    case 4:
        ui.universityHeader();
        linearStartLoad = std::chrono::high_resolution_clock::now();
        // rank = std::stoi(key);
        for (int i = 0; i < size; i++)
        {
            if (universityList[i].getFsrRank() == rank)
            {

                if (!found)
                {
                    found = true;
                    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - linearStartLoad).count();
                }
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;

    case 5:
        ui.universityHeader();
        linearStartLoad = std::chrono::high_resolution_clock::now();
        // rank = std::stoi(key);
        for (int i = 0; i < size; i++)
        {
            if (universityList[i].getErRank() == rank)
            {

                if (!found)
                {
                    found = true;
                    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - linearStartLoad).count();
                }
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;

    case 6:
        ui.universityHeader();
        linearStartLoad = std::chrono::high_resolution_clock::now();
        // rank = std::stoi(key);
        for (int i = 0; i < size; i++)
        {
            if (universityList[i].getArRank() == rank)
            {
                if (!found)
                {
                    found = true;
                    duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - linearStartLoad).count();
                }
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;
    default:
        break;
    }
    return duration;
}

void Algorithms::binarySearch(University universityList[], int size, int rank)
{
    UI ui;
    int start = 0;
    int end = size;
    const int maxSize = 1442;
    int mid = (start + end) / 2;
    int current;
    University tempUniList[maxSize];

    while (true)
    {
        mid = (start + end) / 2;
        int uniRank = universityList[mid].getRank();
        int arRank = universityList[mid].getArRank();
        int fsrRank = universityList[mid].getFsrRank();
        int erRank = universityList[mid].getErRank();

        // switch (choice)
        // {
        // case RANK:
        //     // Searching by University Rank
        //     current = universityList[mid].getRank();
        //     break;

        // case AR_RANK:
        //     // Searching by AR Rank
        //     current = universityList[mid].getArRank();
        //     break;

        // case FSR_RANK:
        //     // Searching by FSR Rank
        //     current = universityList[mid].getFsrRank();
        //     break;

        // case ER_RANK:
        //     // Searching by ER Rank
        //     current = universityList[mid].getErRank();
        //     break;

        // default:
        //     break;
        // }

        if (uniRank == rank || arRank == rank || fsrRank == rank || erRank == rank)
        {
            std::cout << "Found " << rank << " at index " << mid << std::endl;
            std::cout << std::endl;
            ui.universityHeader();
            std::cout << universityList[mid] << std::endl
                      << std::endl;
            break;
        }
        else if (current < rank)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        if (start > end)
        {
            std::cout << "Not found." << std::endl;
            break;
        }
    }
}

int *Algorithms::getRank(University universityList[], int mid, int choice)
{
    static int currentRank[2];
    switch (choice)
    {
    case RANK:
        // Searching by University Rank
        currentRank[0] = universityList[mid].getRank();
        currentRank[1] = universityList[mid - 1].getRank();
        break;

    case AR_RANK:
        // Searching by AR Rank
        currentRank[0] = universityList[mid].getArRank();
        currentRank[1] = universityList[mid - 1].getArRank();
        break;

    case FSR_RANK:
        // Searching by FSR Rank
        currentRank[0] = universityList[mid].getFsrRank();
        currentRank[1] = universityList[mid - 1].getFsrRank();
        break;

    case ER_RANK:
        // Searching by ER Rank
        currentRank[0] = universityList[mid].getErRank();
        currentRank[1] = universityList[mid - 1].getErRank();
        break;

    default:
        break;
    }

    return currentRank;
}

long long Algorithms::binarySearchWithDuplicates(University universityList[], int size, int choice, int rank)
{
    int start = 0;
    int end = size;
    int mid;
    int *currentRank;
    long long duration;
    auto binaryStartLoad = std::chrono::high_resolution_clock::now();
    while (start <= end)
    {
        // std::cout << "looping" << std::endl;
        mid = (start + end) / 2;
        currentRank = getRank(universityList, mid, choice);
        // Check if the mid element is equal to the target
        if (currentRank[0] == rank)
        {
            duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - binaryStartLoad).count();
            // Handle duplicates by finding the leftmost occurrence
            while (mid > 0 && currentRank[1] == rank)
            {
                currentRank = getRank(universityList, --mid, choice);
            }
            UI ui;
            // ui.universityHeader();
            // Print all the duplicates
            while (currentRank[0] == rank)
            {
                std::cout << universityList[mid];
                currentRank = getRank(universityList, ++mid, choice);
            }
            std::cout << std::endl;
            return duration;
        }
        // If the mid element is greater than the target, search in the left half
        else if (currentRank[0] > rank)
        {
            end = mid - 1;
        }
        // If the mid element is less than the target, search in the right half
        else
        {
            start = mid + 1;
        }
    }
    std::cout << "Not found." << std::endl;
    return 0;
}