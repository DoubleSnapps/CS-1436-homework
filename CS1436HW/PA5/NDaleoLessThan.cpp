/*  This function finds and displays values in
    an array lesser than a specified value. It
    takes inputs of array size, a value for each
    index of the array, and a value to search for
    lesser values in the array all from the user.
    It outputs the numbers within the array lesser
    than the value to search with.  */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int getIntInput(string msg);
void displayLesserValues(const int[], int, int);

int main()
{

    int size, i, searchValue;

    size = getIntInput("Enter size of Array: ");
    cout << endl;

    int array[size] = {0};

    for (i = 0; i < size; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> array[i];
    }

    cout << endl;

    cout << "Enter int value to search array with: ";
    cin >> searchValue;
    cout << endl;

    displayLesserValues(array, size, searchValue);

    return 0;
}

/*  This function searches an array and collects
    and displays values lesser than the search value.
    Requires: array to search (const int array)
    Requires: # of elements in array (int)
    Requires: value to search with (int)    */
void displayLesserValues(const int array[], int size, int searchValue)
{

    int lowerNumbers[size] = {0}, i, j;

    for (i = 0, j = 0; i < size; i++)
    {

        // if value is less than the search value, add to lower nums array
        if (array[i] < searchValue)
        {
            lowerNumbers[j] = array[i];
            // increment index of lower numbers
            j++;
        }
    }

    // only runs if any lesser values were collected
    if (j > 0)
    {

        cout << "The array contained " << j << " number(s) less than " << searchValue << endl;

        for (i = 0; i < j; i++)
        {
            cout << lowerNumbers[i] << " ";
        }
    }
    else
    {
        cout << "No values less than " << searchValue << " were found." << endl;
    }
}

/*  This function gets a non-negative
    int from the user. It runs
    until a valid (>=1) value is entered.
    Requires: prompt for user (string)
    Returns: user entered value (double)  */
int getIntInput(string msg)
{

    int value = 0;
    bool validValue = true;

    do
    {
        cout << (validValue ? "" : "Invalid Value Entered; Try again\n");
        cout << msg;
        cin >> value;

        validValue = (value > 0);

    } while (!validValue);

    return value;
}