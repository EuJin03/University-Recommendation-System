#include <iostream>
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

void Algorithms::countSort(University universityList[], int size, SortType sortType)
{
    if (sortType == INSTITUTION)
    {
        countSortString(universityList, size, sortType);
    }
    else
    {
        countSortInteger(universityList, size, sortType);
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
void Algorithms::countSortInteger(University universityList[], int size, SortType sortType)
{
    int n = size;
    int maxScore = getMaxScore(universityList, size, sortType);

    std::vector<University> output(n);
    std::vector<int> count(maxScore + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int score = getScore(universityList[i], sortType);
        count[score]++;
    }

    for (int i = 1; i <= maxScore; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int score = getScore(universityList[i], sortType);
        output[count[score] - 1] = universityList[i];
        count[score]--;
    }

    for (int i = 0; i < n; i++)
    {
        universityList[i] = output[i];
    }
}

void Algorithms::countSortString(University universityList[], int size, SortType sortType)
{
    int n = size;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int len = getScoreString(universityList[i], sortType).length();
        maxLen = std::max(maxLen, len);
    }

    int k = 128;

    std::vector<University> output(n);
    std::vector<int> count(k, 0);

    for (int len = maxLen; len > 0; len--)
    {
        for (int i = 0; i < k; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
        {
            std::string institution = getScoreString(universityList[i], sortType);
            if (institution.length() < len)
                count[0]++;
            else
                count[int(institution[len - 1])]++;
        }

        for (int i = 1; i < k; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            std::string institution = getScoreString(universityList[i], sortType);
            if (institution.length() < len)
            {
                output[count[0] - 1] = universityList[i];
                count[0]--;
            }
            else
            {
                output[count[int(institution[len - 1])] - 1] = universityList[i];
                count[int(institution[len - 1])]--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            universityList[i] = output[i];
        }
    }
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

void Algorithms::linearSearch(University universityList[], int size, int criteria, std::string key)
{
    switch (criteria)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            if (universityList[i].getInstitution() == key)
            {
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;
    case 2:
        for (int i = 0; i < size; i++)
        {
            if (universityList[i].getLocale() == key)
            {
                std::cout << universityList[i];
            }
        }
        std::cout << std::endl;
        break;
    default:
        break;
    }
}




void Algorithms::binarySearch(University universityList[], int choice, int rank)
{
    UI ui;
    int start = 0;
    int end = (sizeof(universityList) / sizeof(University)) - 1;
    int mid = (start + end) / 2;
    int current;
    while(true)
    {
        mid = (start + end) / 2;
        switch (choice)
        {
        case RANK:
            // Searching by University Rank
            current = universityList[mid].getRank();
            break;
        
        case AR_RANK:
            // Searching by AR Rank
            current = universityList[mid].getArRank();
            break;

        case FSR_RANK:
            // Searching by FSR Rank
            current = universityList[mid].getFsrRank();
            break;

        case ER_RANK:
            // Searching by ER Rank
            current = universityList[mid].getErRank();
            break;

        default:
            break;
        }

        
        if (current == rank)
        {
            std::cout << "Found " << rank << " at index " << mid << std::endl;
            std::cout << std::endl;
            ui.universityHeader();
            std::cout << universityList[mid] << std::endl << std::endl;
            break;
        } else if (current < rank)
        {
            start = mid + 1;
        } else
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
