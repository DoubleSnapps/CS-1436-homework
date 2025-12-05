/*  This function determines a participant's talent show score.
    It takes an input 5 judge score [0.0-10.0] from the user. 
    It outputs the average score, dropping the lowest and 
    highest score given to the contestant.  */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// General Array Functions
void copyArray(const double[], double[], int);
double findLowest(const double[], int);
double findHighest(const double[], int);
void sortArray(double[], int);

// Talent Functions
void getJudgeData(double&, int);
void calcScore(const double[], int);

int main()
{

    const int SIZE = 5;
    int i;
    double scores[SIZE] = {0}, judgeScore;

    for(i = 0; i < SIZE; i++)
    {
        // collect score in ref parameter, then save ref param to array
        getJudgeData(judgeScore, (i + 1));
        scores[i] = judgeScore;
    }

    // call score calc + display function    
    calcScore(scores, SIZE);


    return 0;

}

/*  This function gets a valid talent show 
    score value from the user. It loops until 
    a value valid is entered [0.0-10.0]. 
    Requires: number of judge (int)
    Returns: score value from [0.0-10.0] (double)  */
void getJudgeData(double &score, int judgeNumber)
{
    bool validScore = true;

    do
    {
        cout << ((validScore) ? "" : "Invalid Score Entered\n"); 
        cout << "Enter Judge #" << judgeNumber << "'s Score: ";
        cin >> score;

        validScore = (score >= -0) && (score <= 10);

    }
    while(!validScore);
    
}

/*  This function calculates and displays a talent show 
    score, dropping the lowest and highest scores received.
    Requires: scores (const double array)
    Requires: # of elements of array (int)  */
void calcScore(const double scores[], int size)
{

    int i;
    double averageScore, scoreTotal = 0;

    for(i = 0; i < size; i++)
    {
        scoreTotal += scores[i];
    }

    // remove the lowest and highest score from the score total
    scoreTotal -= findLowest(scores, size);
    scoreTotal -= findHighest(scores, size);

    // average is total / size - 2 to account for 2 removed scores
    averageScore =  scoreTotal / (size - 2);

    cout << "The Score is " << averageScore << " points.";

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
double findLowest(const double array[], int size)
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
double findHighest(const double array[], int size)
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