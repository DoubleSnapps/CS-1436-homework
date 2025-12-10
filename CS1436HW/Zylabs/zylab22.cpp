/*  This program finds the sum of neighbors of a
    int number in an 10 by 8 array of integers. It
    takes an input of random seed if time is not used.
    It outputs the sum of neighbors for each column
    for each row (80 sums).  */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROWS = 10, COLUMNS = 8;

int findSumOfNeighbors(const int[][COLUMNS], int, int, const int, const int);
void randFill2DArray(int[][COLUMNS], const int);

int main()
{

    int seed, rowIndex = 0, columnIndex = 0, sum = 0;
    bool useTime = false;

    int array[ROWS][COLUMNS] = {0};

    // get seed
    cin >> seed;

    // seed = (useTime) ? time(0) : seed;

    // set seed
    srand(seed);

    // fill array with random values
    randFill2DArray(array, ROWS);

    // print out each sum of elements neighbors
    for (rowIndex = 0; rowIndex < ROWS; rowIndex++)
    {
        for (columnIndex = 0; columnIndex < COLUMNS; columnIndex++)
        {
            // calculate sum
            sum = findSumOfNeighbors(array, rowIndex, columnIndex, ROWS, COLUMNS);

            // print statement
            cout << "The sum of the neighbors of array[";
            cout << rowIndex << "][" << columnIndex << "] is ";
            cout << sum << "." << endl;
        }
    }

    return 0;
}

/*  This function fills a 8 by 10 2d array of ints with random values [1-10].
    Requires: 2d int array 10 columns and 8 rows (int array[][])
    Requires: rows in column (const int)    */
void randFill2DArray(int array[][COLUMNS], const int rows)
{

    int random = 0, i, j;

    for (i = 0; i < COLUMNS; i++)
    {

        for (j = 0; j < ROWS; j++)
        {
            // random is restricted to [1,10]
            random = rand() % 10 + 1;
            // set array value to random value
            array[j][i] = random;
        }
    }
}

/*  This function finds the sum of numbers touched
    by a number specified by a row and column.
    Requires: int array (const int[][])
    Requires: row index of number (int)
    Requires: column index of number (int)
    Requires: # of rows (const int)
    Requires: # of columns (const int)  */
int findSumOfNeighbors(const int array[][COLUMNS], int rowIndex, int columnIndex, const int rows, const int columns)
{
    int sum = 0;

    /*  if column is not near the "edge", we can find the nearby
        value by adding and/or subtracting 1 from the current columnIndex  */

    sum += ((columnIndex > 0) ? array[rowIndex][columnIndex - 1] : 0);

    sum += ((columnIndex < 7) ? array[rowIndex][columnIndex + 1] : 0);

    /*  if row is not near the "edge", we can find the nearby
       value by adding and/or subtracting 1 from the current rowIndex  */

    sum += ((rowIndex > 0) ? array[rowIndex - 1][columnIndex] : 0);

    sum += ((rowIndex < 9) ? array[rowIndex + 1][columnIndex] : 0);

    return sum;
}