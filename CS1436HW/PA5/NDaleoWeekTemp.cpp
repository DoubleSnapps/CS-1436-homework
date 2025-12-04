/*  This function generates a weekly weather report. It takes an 
    input of temperature in fahrenheit from the user. It outputs 
    a formatted weekly weather report, with the temperature for 
    each day, weekly average, and weekly high and low. I went a 
    little overboard with the functions. sorry  */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// General Array Functions
void copyArray(const double[], double[], int);
double findLowestElement(const double[], int);
double findHighestElement(const double[], int);
void sortArray(double[], int);
int findIndexAtValue(const double[], double, int);

// Weather Functions
double getValidTemp(string day);
void printWeeklyTempReport(const double[], int, int);
void printTempHighLow(string, string, double, double, int);

// Misc Functions
void printLine(int);


const int SIZE = 7;
const string days[SIZE] = {"Mon", "Tues", "Wednes", "Thurs", "Fri", "Satur", "Sun"};

int main()
{

    double temperatures[SIZE] = {0}, low, high;
    int i, spacing = 15;
    string lowestDay, highestDay;

    // user input

    for(i = 0; i < SIZE; i++)
    {
        temperatures[i] = getValidTemp(days[i]);
    }

    // calculation

    // get weekly high and low
    low = findLowestElement(temperatures, SIZE);
    high = findHighestElement(temperatures, SIZE);

    // find days which weekly high and low occurred
    lowestDay = days[findIndexAtValue(temperatures, low, SIZE)];
    highestDay = days[findIndexAtValue(temperatures, high, SIZE)];

    // print weather reports

    printWeeklyTempReport(temperatures, SIZE, spacing);

    printTempHighLow(highestDay, lowestDay, high, low, spacing);

    return 0;

}

/*  This function prints a report for the highest and lowest temperature of a given week.
    Requires: prefix of day with weekly high (string)
    Requires: prefix of day with weekly low (string)
    Requires: weekly high in fahrenheit (double)
    Requires: weekly low in fahrenheit (double)
    Requires: line spacing (int)    */
void printTempHighLow(string highDay, string lowDay, double highTemp, double lowTemp, int spacing)
{
    cout << left;
    cout << setw(spacing) << "Weekly High" << setw(spacing) << "Weekly Low" << endl;
    cout << setw(spacing) << (highDay + "day") << setw(spacing) << (lowDay + "day") << endl;
    cout << setw(spacing) << highTemp << setw(spacing) << lowTemp;
    cout << endl;
}

/*  This function prints the weekly temperature
    report, along with the average.
    Requires: the week's temperatures (const double array)
    Requires: # of elements in array (int)
    Requires: line spacing (int) */
void printWeeklyTempReport(const double temperatures[], int size, int spacing)
{

    int i;
    double weeklyAverage = 0;

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

    for(i = 0; i < size; i++)
    {
        weeklyAverage += temperatures[i];
    }

    weeklyAverage /= size;

    cout << "Weekly Average: " << weeklyAverage << endl;

    printLine(66);

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

/*  This function finds the last instance 
    of a given value in an array, and returns
    said value's index.
    Requires: array to search (const double array)
    Requires: value to search for (double)
    Requires: # of elements in array (int)  */
int findIndexAtValue(const double array[], double searchValue, int size)
{

    bool equal = false;
    int originalIndex = 0, i = 0;

    for (i = 0; (!equal && i < size); i++)
    {
        equal = array[i] == searchValue;
    }

    originalIndex = i - 1;

    return originalIndex;

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