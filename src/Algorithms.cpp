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

/**
 * @brief Count Sort Algorithm.
 * @param uniArr std::vector of University objects to be sorted.
 * @param sortType The type of sorting to be applied.
 * @return The sorted std::vector of University objects.
 *
 * This function implements the Count Sort algorithm to sort the uniArr std::vector. The sortType parameter is used
 * to determine the sorting criteria.
 */
std::vector<University> Algorithms::countSort(std::vector<University> &uniArr, SortType sortType)
{
    // The number of universities.
    int n = uniArr.size();

    // Find the maximum score to initialize the count array.
    int maxScore = getMaxScore(uniArr, sortType);

    // Initialize the output std::vector and the count array.
    std::vector<University> output(n);
    std::vector<int> count(maxScore + 1, 0);

    // Count the number of times each score appears in the input std::vector.
    for (int i = 0; i < n; i++)
    {
        int score = getScore(uniArr[i], sortType);
        count[score]++;
    }

    // Transform count[i] so that count[i] now contains the actual position of this score in the output array.
    for (int i = 1; i <= maxScore; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output std::vector.
    for (int i = n - 1; i >= 0; i--)
    {
        int score = getScore(uniArr[i], sortType);
        output[count[score] - 1] = uniArr[i];
        count[score]--;
    }

    uniArr = output;

    return output;
}

/**
 * @brief Get the maximum score from a std::vector of University objects.
 * @param uniArr std::vector of University objects.
 * @param sortType The type of sorting to be applied.
 * @return The maximum score.
 *
 * This function iterates through the uniArr std::vector to find the maximum score based on the sortType parameter.
 */
int Algorithms::getMaxScore(const std::vector<University> &uniArr, SortType sortType)
{
    int n = uniArr.size();
    int maxScore = getScore(uniArr[0], sortType);

    for (int i = 1; i < n; i++)
    {
        int score = getScore(uniArr[i], sortType);
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