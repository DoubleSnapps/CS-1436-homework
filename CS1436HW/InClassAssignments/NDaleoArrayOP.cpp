/*  This menu based program preforms a variety 
    of operations to an integer array. It takes 
    an input of menu actions from the user, as 
    well an input for each value of the int array. 
    It outputs the result of menu actions. */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void copyArray(const int[], int[], int);
int findLowestElement(const int[], int);
int findHighestElement(const int[], int);
bool compareArrays(const int[], const int[], int);
void sortArray(int[], int);

const int SIZE = 10;
const string waitPrompt = "Enter anything to continue: ";

int main()
{

    int userNumbers[SIZE] = {0}, copiedArray[SIZE] = {0};
    bool arrayFilled = false;
    char action = 'A';
    string aPrompt = "Enter Character for Action:\n\n", fillPrompt = "Fill Array (F): ",
           exitPrompt = "Exit Program (X): ", indexPrompt = "Enter value of index #",
           copyPrompt = "Copy Array (C): ", lowestPrompt = "Find lowest value (L): ",
           highestPrompt = "Find highest value (H):", comparePrompt = "Compare if Arrays are equal (E):";

    // runs while array is empty
    while (!arrayFilled && action != 'X' && action != 'x')
    {

            cout << aPrompt;
            cout << "\t" << fillPrompt << endl;
            cout << "\t" << exitPrompt << endl;
            cin >> action;

            if (action == 'F' || action == 'f')
            {
                for (int i = 0; i < SIZE; i++)
                {
                    cout << indexPrompt << (i + 1) << ": ";
                    cin >> userNumbers[i];
                }

                cout << "Array filled." << endl;
                arrayFilled = true;
            }
        }

    while (action != 'X' && action != 'x')
    {

        cout << aPrompt;
        cout << "\t" << copyPrompt << endl;
        cout << "\t" << lowestPrompt << endl;
        cout << "\t" << highestPrompt << endl;
        cout << "\t" << comparePrompt << endl;
        cout << "\t" << exitPrompt << endl;
        cin >> action;

        if (action == 'C' || action == 'c')
        {
            copyArray(userNumbers, copiedArray, SIZE);
            cout << "Array Copied." << endl;
        }

        else if (action == 'L' || action == 'l')
        {
            findLowestElement(userNumbers, SIZE);
        }

        else if (action == 'H' || action == 'h')
        {
            findHighestElement(userNumbers, SIZE);
        }

        else if (action == 'E' || action == 'e')
        {
            compareArrays(userNumbers, copiedArray, SIZE);
        }
    }
}

/*  This function copys the copy array to the paste array.
    The size parameter must be the size of the arrays, or
    the size of the smaller array, if they differ.
    Requires: copy array (const int array)
    Requires: paste array (const int array)
    Requires: # of elements of smaller array (int)
    Returns: copy array's contents in paste array   */
void copyArray(const int copyArray[], int pasteArray[], int size)
{

    for (int i = 0; i < size; i++)
    {
        pasteArray[i] = copyArray[i];
    }

}

/*  This function finds the lowest value within an int array.
    The function copys the array, sorts it from least to greatest,
    and then takes the 0th element of the sorted array.
    Requires: array (const int array)
    Requires: # of elements in array (int)  */
int findLowestElement(const int array[], int size)
{
    char ch;
    int lowest;
    int sortedArray[size] = {0};

    copyArray(array, sortedArray, size);

    sortArray(sortedArray, size);

    lowest = sortedArray[0];

    cout << "The lowest value is " << lowest << endl;
    cout << waitPrompt;
    cin >> ch;

    return lowest;
}

/*  This function finds the highest value within an int array.
    The function copys the array, sorts it from least to greatest,
    and then takes the last element of the sorted array.
    Requires: array (const int array)
    Requires: # of elements in array (int)  */
int findHighestElement(const int array[], int size)
{
    char ch;
    int highest;
    int sortedArray[size] = {0};

    // copy array to prevent changes to input array
    copyArray(array, sortedArray, size);

    // sort new array
    sortArray(sortedArray, size);

    // highest is last value of array
    highest = sortedArray[size - 1];

    cout << "The highest value is " << highest << endl;
    cout << waitPrompt;
    cin >> ch;

    return highest;
}

/*  This function finds if two integer arrays are equal
    in all of their indexes. This function stops looping
    two indexes differ in value, or the arrays are exhausted.
    Requires: first array (const int array)
    Requires: second array (const int array)
    Requires: # of elements of array (int)  */
bool compareArrays(const int array1[], const int array2[], int size)
{
    bool equal = true;
    char ch;

    // equal is used as a short circuit, so loop ends on 1st false
    for (int i = 0; (equal && i < size); i++)
    {
        equal = array1[i] == array2[i];
    }

    cout << "The arrays are " << (equal ? "" : "not ") << "equal." << endl;
    cout << waitPrompt;   
    cin >> ch;

    return equal;
}

/*  This function sorts an array from least to
    greatest, least 0th, greatest last. The
    argument array will be altered.
    Requires: array to sort (int array)
    Requires: # of elements in array (int)
    Returns: sorted array (int array)   */
void sortArray(int array[], int size)
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