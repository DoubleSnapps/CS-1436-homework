/*  This program determines the frequency of dice
    rolls of a 6-sided die. It takes an input of number
    of times to roll from the user. It outputs the
    frequency and percentage of face sides for the rolls.*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void dispFreqAndPercentages(unsigned int[], int);

int main()
{

    const int SIZE = 7;

    bool useTime = false;
    int rolls = 0, i, seed = 0, currentRoll = 0;
    string rollsMsg = "Please enter the number of times to roll the die: ";

    unsigned int frequency[SIZE] = {0};

    // Seed Generation

    if (!useTime)
    {
        cin >> seed;
    }

    srand(useTime ? time(0) : seed);

    // User Input

    cout << rollsMsg;
    cin >> rolls;
    cout << endl;

    // Dice rolling

    for (i = 0; i < rolls; i++)
    {
        // [1-6]
        currentRoll = rand() % 6 + 1;

        // add 1 to the index rolled (index 0 empty)
        frequency[currentRoll]++;
    }

    dispFreqAndPercentages(frequency, rolls);

    return 0;
}

/*  This function displays the frequency and percentage of 6 sided dice rolls.
    Requires: array of sum of rolls (unsigned int array)
    Requires: number of rolls (int) */
void dispFreqAndPercentages(unsigned int frequency[], int rolls)
{
    string face = "Face #", freq = ": Frequency:", per = " Percentage:";
    double percentage;

    cout << right << fixed;

    // only runs if rolls is > 0
    if (rolls > 0)
    {

        for (int i = 1; i <= 6; i++)
        {
            // times rolled / total rolls * 100
            percentage = (frequency[i] / static_cast<double>(rolls)) * 100;

            // prints formatted report

            cout << face << setprecision(0) << (i) << freq;
            cout << setw(6) << frequency[i];
            cout << per << setprecision(1) << setw(6) << percentage;
            cout << endl;
        }
    }
}
