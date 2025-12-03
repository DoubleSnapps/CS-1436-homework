#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    double average = 0;
    int scores[120] = {0}, scoresEntered = 0, belowAverage[120] = {0}, i = 0, belowAvgEntered = 0, score = 0;

    // score collection
    while (score != -999 && scoresEntered < 120)
    {

        if (scoresEntered == 0)
        {
            cout << "Enter the first score or -999 to end input: ";
            cin >> score;
        }
        else
        {
            cout << "Enter the next score or -999 to end input: ";
            cin >> score;
        }

        if (score != -999)
        {

            // score validation
            if (score >= 0 && score <= 150)
            {
                scores[scoresEntered] = score;
                scoresEntered++;
            }
            // if valid, save to array
            else
            {
                cout << "Error, " << score << " is not a valid score." << endl;
                cout << "Valid scores are in the range 0 through 150 inclusive." << endl;
            }
        }
    }

    if (scoresEntered > 0)
    {
        // print if array is filled
        if (scoresEntered == 120)
            cout << "Array is full! Ending input." << endl;

        // sum all scores into average
        for (i = 0; i <= scoresEntered; i++)
        {
            average += scores[i];
        }

        // divide by amount of scores to find average
        average /= scoresEntered;

        for (i = 0, belowAvgEntered = 0; i < scoresEntered; i++)
        {
            // if score[i] is less than average
            if (scores[i] < average)
            {
                // save score[i] to belowAverage[j]
                belowAverage[belowAvgEntered] = scores[i];
                // increment j when a score is below average
                belowAvgEntered++;
            }
        }

        cout << fixed << setprecision(1) << endl;
        cout << "The average of the scores is: " << average << "." << endl;
        cout << setprecision(0);

        if (belowAvgEntered > 0)
        {
            cout << "The scores below the average were: ";
            // for i in below average scores
            for (scoresEntered = 0; scoresEntered < belowAvgEntered; scoresEntered++)
            {
                // print each below average score
                cout << belowAverage[scoresEntered] << " ";
            }
            cout << endl;
        }
    }
    // print if user didn't enter a valid score
    else
    {
        cout << "No valid scores were entered." << endl;
    }

    return 0;

}