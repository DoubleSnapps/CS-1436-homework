#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int numbers[SIZE] = {0}, i = 0, j = 0, prevIndex = 0;

    for (i = 0; i < SIZE; i++)
    {
        cout << "Enter a Integer Value: ";
        cin >> numbers[i];
    }

    for (i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    // sort from smallest [0] - to largest [n-1]
    for (i = 0; i < SIZE; i++)
    {
        // j starts at the index after i, to check the next index value
        for (j = i + 1; j < SIZE; j++)
        {
            // if index i (preceding) is greater than j, then we place j behind i, as j comes first
            if (numbers[i] > numbers[j])
            {
                // save numbers[i] to prevIndex
                prevIndex = numbers[i];
                // set numbers[i] to numbers[j]
                numbers[i] = numbers[j];
                // numbers[j] is set to the previous value of numbers[i]
                numbers[j] = prevIndex;
            }
        }
    }

    cout << "The smallest number is " << numbers[0] << endl;
    cout << "The largest number is " << numbers[(SIZE - 1)] << endl;

    return 0;

}