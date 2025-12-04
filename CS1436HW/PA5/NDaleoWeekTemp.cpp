#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double getValidTemp(string day);
void copyArray(const double[], double[], int);
double findLowestElement(const double[], int);
double findHighestElement(const double[], int);
void sortArray(double[], int);
void printLine(int);

const int SIZE = 7;
const string days[SIZE] = {"Mon", "Tues", "Wednes", "Thurs", "Fri", "Satur", "Sun"};

int main()
{

    double temperatures[SIZE] = {0}, averageTemp;
    int i, lowestDay, highestDay, spacing = 10;

    for(i = 0; i < SIZE; i++)
    {
        temperatures[i] = getValidTemp(days[i]);
    }


    printWeeklyTempReport(temperatures, spacing, SIZE);




}

void printWeeklyTempReport(const double temperatures[], int spacing, int size)
{

    int i;

    cout << left << endl;

    cout << "All Temps in °F" << endl; 

    for(i = 0; i < size; i++)
    {
        cout << setw(spacing) << (days[i] + "day");
    }

    cout << left << endl << fixed << setprecision(2) << showpoint;

    for(i = 0; i < size; i++)
    {
        cout << setw(spacing) << temperatures[i];
    }

    cout << endl;

    printLine(66);

    cout << setw(spacing) << "Weekly High" << setw(2 * spacing) << "Weekly Low";



}

/*  This function prints a line of "-" 
    dashes a user defined amount of times. 
    Requires: # of dashes to print (int)  */
void printLine(int length)
{

    for(int i = 0; i < length; i++)
    {
        cout << "-";
    }

    cout << endl;

}

/*  This function gets a valid fahrenheit 
    value from the user. It loops until a 
    value valid is entered. 
    Requires: prefix of day of the week (string)
    Returns: fahrenheit temperature value from [-50, 150] (double)  */
double getValidTemp(string day)
{
    double temp;
    bool validTemp;

    do
    {
        cout << "Enter " << day << "day's temperature in °F: ";
        cin >> temp;

        validTemp = (temp >= -50) && (temp <= 150);

    }
    while(!validTemp);

    return temp;
    
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