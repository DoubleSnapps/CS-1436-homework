/*  This function finds the lowest, highest,
    total, and average of a set of numbers gathered 
    from a file. It takes an input of file name from 
    the user, the file should have 1 number per line. 
    It outputs the lowest and highest number in the file, 
    as well as the total of all numbers, and the average 
    number of the file.  */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// General Array Functions
void copyArray(const double[], double[], int);
double findLowestElement(const double[], int);
double findHighestElement(const double[], int);
void sortArray(double[], int);

// File Functions
int findLinesInFile(string);


int main()
{

    int size = 1, i;
    double lowest, highest, average, total = 0;
    string ifName = "numbers.txt";

    ifstream inputFile;

    // get file name
    cout << "Enter input file name: ";
    cin >> ifName;
    cout << endl;

    // find # of lines in file
    size = findLinesInFile(ifName);

    // open after finding lines, as not to open the same file twice and cause issues
    inputFile.open(ifName);

    // we divide by 0, so we want to make sure the file is open, and size != 0
    if (inputFile && size)
    {

        // create number array with size of lines in file
        double numbers[size];

        for (i = 0; i < size; i++)
        {
            inputFile >> numbers[i];
            total += numbers[i];
        }

        average = total / size;

        lowest = findLowestElement(numbers, size);
        highest = findHighestElement(numbers, size);

        // result output

        cout << "Lowest Number is: " << lowest << endl;
        cout << "Highest Number is: " << highest << endl;
        cout << "Total of numbers is: " << total << endl;
        cout << "Average of number is: " << average << endl;

        inputFile.close();
    }
    else
    {
        cout << "Error: File was could not be opened or was empty;" << endl;
    }

    return 0;
}

/*  This function finds the number of lines in a file.
    Requires: file name (string)
    Returns: # of lines (int)   */
int findLinesInFile(string ifName)
{
    int lines = 0;
    ifstream inputFile;
    string str;

    inputFile.open(ifName);

    while (inputFile >> str)
    {
        lines++;
    }

    inputFile.close();

    return lines;
}

/*  This function copys the copy array to the paste array.
    The size parameter must be the size of the arrays, or
    the size of the smaller array, if they differ.
    Requires: copy array (const double array)
    Requires: paste array (double array)
    Requires: # of elements of smaller array (int)
    Returns: copy array's contents in paste array (double array) */
void copyArray(const double copyArray[], double pasteArray[], int size)
{

    for (int i = 0; i < size; i++)
    {
        pasteArray[i] = copyArray[i];
    }
}

/*  This function finds the lowest value within an double array.
    The function copys the array, sorts it from least to greatest,
    and then takes the 0th element of the sorted array.
    Requires: array (const double array)
    Requires: # of elements in array (int)  */
double findLowestElement(const double array[], int size)
{
    double lowest;
    double sortedArray[size] = {0};

    copyArray(array, sortedArray, size);

    sortArray(sortedArray, size);

    lowest = sortedArray[0];

    return lowest;
}

/*  This function finds the highest value within an double array.
    The function copys the array, sorts it from least to greatest,
    and then takes the last element of the sorted array.
    Requires: array (const double array)
    Requires: # of elements in array (int)  */
double findHighestElement(const double array[], int size)
{
    double highest;
    double sortedArray[size] = {0};

    // copy array to prevent changes to input array
    copyArray(array, sortedArray, size);

    // sort new array
    sortArray(sortedArray, size);

    // highest is last value of array
    highest = sortedArray[size - 1];

    return highest;
}

/*  This function sorts an array from least to
    greatest, least 0th, greatest last. The
    argument array will be altered.
    Requires: array to sort (double array)
    Requires: # of elements in array (int)
    Returns: sorted array (double array)   */
void sortArray(double array[], int size)
{

    int prevIndex = 0;

    // sort from smallest [0] - to largest [n-1]
    for (int i = 0; i < size; i++)
    {
        // j starts at the index after i, to check the next index value
        for (int j = i + 1; j < size; j++)
        {
            // if index i (preceding) is greater than j, then we place j behind i, as j comes first
            if (array[i] > array[j])
            {
                // save numbers[i] to prevIndex
                prevIndex = array[i];
                // set numbers[i] to numbers[j]
                array[i] = array[j];
                // numbers[j] is set to the previous value of numbers[i]
                array[j] = prevIndex;
            }
        }
    }
}