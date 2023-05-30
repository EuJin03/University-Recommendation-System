#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

const int MAX_UNIVERSITY = 1423;

struct insertionSortName
{
    string universityRow[10];
};

void sortingChoice(int choice)
{
    switch (choice)
    {
    case 1: /* constant-expression */
        /* code */
        performSorting(choice);
        break;
    case 2:
        performSorting(choice);
        break;
    case 3:
        performSorting(choice);
        break;
    default:
        cout << "invalid input" << endl;
        break;
    }
}

bool compareScore(int choice, const insertionSortName &row1, const insertionSortName &row2)
{
    if (choice == 1)
    {
        return row1.universityRow[4] < row2.universityRow[4];
    }
    else if (choice == 2)
    {
        return row1.universityRow[8] < row2.universityRow[8];
    }
    else if (choice == 3)
    {
        return row1.universityRow[6] < row2.universityRow[6];
    }

    // Handle invalid choice
    cout << "Invalid choice in compareScore." << endl;
    return false;
}

void insertionSort(int choice, insertionSortName arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        insertionSortName key = arr[i];
        int j = i - 1;

        while (j >= 0 && compareScore(choice, arr[j], key))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

string trim(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == string::npos || last == string::npos)
    {
        return "";
    }
    return str.substr(first, last - first + 1);
}
void performSorting(int choice)
{
    insertionSortName universities[MAX_UNIVERSITY];
    ifstream file("/Users/eugen/Home/Desktop/Degree(CYB)/Sem 2/Data Structure/university_recommendation_system/test/2023_QS_World_University_Rankings.csv");

    if (!file.is_open())
    {
        cout << "Failed to open file." << endl;
    }

    string ignoreLine;
    getline(file, ignoreLine);

    int universityCount = 0;
    string line;

    while (getline(file, line) && universityCount < MAX_UNIVERSITY)
    {

        istringstream iss(line);
        string field;
        insertionSortName university;

        int col = 0;

        while (getline(iss, field, ',') && col < 10)
        {
            field = trim(field);
            if (!field.empty() && field.front() == '"')
            {
                field = field.substr(1, field.length() - 2);
            }
            university.universityRow[col] = field;
            col++;
        }

        universities[universityCount] = university;
        universityCount++;
    }

    file.close();

    insertionSort(choice, universities, universityCount);

    cout << "The university information in descending order by university name (First 100 rows)" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "Rank Institution LocationCode Location ArS ArR ErS ErR FsrS FsrR" << endl;
    cout << "=====================================================================================" << endl;

    // Print the sorted data
    int rowCount = 0;
    for (int i = 0; i < universityCount && rowCount < 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << universities[i].universityRow[j] << "\t";
        }
        cout << endl;
        rowCount++;
    }

    cout << "=====================================================================================" << endl;
}

int main()
{

    char cont;
    do
    {
        int choice;

        cout << "Sort the university information by 3 function : " << endl;
        cout << "1. Sort by Academic Reputation Score" << endl;
        cout << "2. Sort by Faculty/Student Ratio Score" << endl;
        cout << "3. Sort by Employee Reputation Score" << endl;
        cout << "Enter 1 to 3, 4 is to quit to main menu : " << endl;
        cin >> choice;

        sortingChoice(choice);

        cout << "\n Do you want to continue? (Type: Y/y)" << endl;
        cin >> cont;
        cout << endl;
    } while (cont == 'Y' || cont == 'y');

    return 0;
}