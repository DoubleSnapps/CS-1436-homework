#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int ROWS = 4, COLUMNS = 3;

void print2DArray(const double[][COLUMNS], const int);
void printStudentAvg(const double[][COLUMNS], const int);
void printExamAverage(const double array[][COLUMNS], const int rows, const int examNumber);

int main()
{
    double array[ROWS][COLUMNS] = {{70, 70, 70}, {80, 56, 70}, {90, 60, 10}, {30, 60, 40}};

    print2DArray(array, ROWS);
    printStudentAvg(array, ROWS);
    printExamAverage(array, ROWS, 1);
    printExamAverage(array, ROWS, 2);
    printExamAverage(array, ROWS, 3);
}

void print2DArray(const double array[][COLUMNS], const int rows)
{

    for (int i = 0; i < rows; i++)
    {

        cout << "student " << (i + 1) << ": ";

        for (int j = 0; j < COLUMNS; j++)
        {
            cout << array[i][j] << " ";
        }

        cout << endl;
    }
}

void printStudentAvg(const double array[][COLUMNS], const int rows)
{

    double total = 0, avg;

    for (int i = 0; i < rows; i++)
    {

        total = 0;

        cout << "student " << (i + 1) << ": ";

        for (int j = 0; j < COLUMNS; j++)
        {
            total += array[i][j];
        }

        avg = total / COLUMNS;

        cout << "average: " << avg << endl;
    }
}

void printExamAverage(const double array[][COLUMNS], const int rows, int examNumber)
{

    double total = 0, avg = 0;

    cout << "exam " << examNumber << " average: ";

    for (int i = 0; i < rows; i++)
    {
        total += array[i][(examNumber - 1)];
        
        avg = total / ROWS;

    }

    cout << avg << endl;

}