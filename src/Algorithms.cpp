#include <iostream>
#include "../include/Algorithms.h"
#include "../include/University.h"

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
int Algorithms::partition(University *uniArr, int start, int pivot, bool registered, int choice)
{
    int i = start - 1;
    if (registered)
    { // Registered users, need to think how to decide on which column to sort on.
        // TODO: Figure out how to decide which column to sort on.
        switch (choice)
        {
        case 1: // Academic Reputation score (arScore)
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getArScore() < uniArr[pivot].getArScore())
                {
                    i++;
                    swap(&uniArr[i], &uniArr[j]);
                }
            }
            break;
        case 2: // Faculty/Student Ratio score (fsrScore)
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getFsrScore() < uniArr[pivot].getFsrScore())
                {
                    i++;
                    swap(&uniArr[i], &uniArr[j]);
                }
            }
            break;
        case 3: // Employer Reputation score (erScore)
            for (int j = start; j < pivot; j++)
            {
                if (uniArr[j].getErScore() < uniArr[pivot].getErScore())
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
void Algorithms::quickSort(University *uniArr, int start, int end, bool registered, int choice)
{
    if (start < end)
    {
        int pivot = partition(uniArr, start, end, registered, choice);
        quickSort(uniArr, start, pivot - 1, registered, choice);
        quickSort(uniArr, pivot + 1, end, registered, choice);
    }
}

// Entry point to the count sort algorithm
std::vector<University> Algorithms::countSort(std::vector<University> &uniArr, SortType sortType)
{
    // Choose the right function based on sort type
    return sortType == INSTITUTION ? countSortString(uniArr, sortType) : countSortInteger(uniArr, sortType);
}

// Function to apply count sort for integers
std::vector<University> Algorithms::countSortInteger(std::vector<University> &uniArr, SortType sortType)
{
    // Initialize relevant variables
    int n = uniArr.size();
    int maxScore = getMaxScore(uniArr, sortType);
    std::vector<University> output(n);
    std::vector<int> count(maxScore + 1, 0);

    // Count the occurrence of each score
    for (const auto &uni : uniArr)
        count[getScore(uni, sortType)]++;

    // Calculate the prefix sum
    for (int i = 1; i <= maxScore; i++)
        count[i] += count[i - 1];

    // Build the output array based on count array
    for (int i = n - 1; i >= 0; i--)
    {
        int score = getScore(uniArr[i], sortType);
        output[--count[score]] = uniArr[i];
    }

    return output;
}

/**
 * @brief Count Sort Algorithm for strings.
 * @param uniArr std::vector of University objects to be sorted.
 * @param sortType The type of sorting to be applied.
 * @return The sorted std::vector of University objects.
 *
 * This function implements the Count Sort algorithm to sort the uniArr std::vector based on strings.
 * The sortType parameter is used to determine the sorting criteria.
 */
std::vector<University> Algorithms::countSortString(std::vector<University> &uniArr, SortType sortType)
{
    // Initialize relevant variables
    int n = uniArr.size();
    int maxLen = 0;

    // Find the maximum length of strings
    for (const auto &uni : uniArr)
        maxLen = std::max(maxLen, (int)getScoreString(uni, sortType).length());

    // Initialize ASCII character range for simplicity
    int k = 128;

    // Initialize relevant vectors
    std::vector<University> output(n);
    std::vector<int> count(k, 0);

    // Count the occurrence of each character for each position in string, sort based on that position
    for (int len = maxLen; len > 0; len--)
    {
        // Reset count array for each new position
        std::fill(count.begin(), count.end(), 0);

        for (int i = 0; i < n; i++)
        {
            std::string institution = getScoreString(uniArr[i], sortType);
            count[institution.length() < len ? 0 : (int)institution[len - 1]]++;
        }

        // Calculate the prefix sum
        for (int i = 1; i < k; i++)
            count[i] += count[i - 1];

        // Build the output array based on count array
        for (int i = n - 1; i >= 0; i--)
        {
            std::string institution = getScoreString(uniArr[i], sortType);
            output[--count[institution.length() < len ? 0 : (int)institution[len - 1]]] = uniArr[i];
        }

        // Update the original array for the next iteration
        uniArr = output;
    }

    return output;
}

// Function to get the maximum score
int Algorithms::getMaxScore(const std::vector<University> &uniArr, SortType sortType)
{
    return getScore(*std::max_element(uniArr.begin(), uniArr.end(), [&](const University &a, const University &b)
                                      { return getScore(a, sortType) < getScore(b, sortType); }),
                    sortType);
}
// Function to get the score based on sort type
int Algorithms::getScore(const University &uni, SortType sortType)
{
    switch (sortType)
    {
    case AR_SCORE:
        return uni.getArScore();
    case FSR_SCORE:
        return uni.getFsrScore();
    case ER_SCORE:
        return uni.getErScore();
    default:
        return -1;
    }
}

// Function to get the string score based on sort type
std::string Algorithms::getScoreString(const University &uni, SortType sortType)
{
    return sortType == INSTITUTION ? uni.getInstitution() : "";
}