

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    double average = 0;
    int scores[120] = {0}, i = 0, belowAverage[120] = {0}, j = 0, k = 0, score = 0;

    // score collection
    while (score != -999 && i < 120)
    {

        if (i == 0)
        {
            cout << "Enter the first score or -999 to end input: ";
            cin >> score;
        }
        else
        {
            cout << "Enter the next score or -999 to end input: ";
            cin >> score;
        }

        // score validation
        if ((score < 0 || score > 150) && score != -999)
        {
            cout << "Error, " << score << " is not a valid score." << endl;
            cout << "Valid scores are in the range 0 through 150 inclusive." << endl;
        }

        // if valid, save to array
        else if (score != -999)
        {
            scores[i] = score;
            i++;
        }
    }

    if (i > 0)
    {
        if(i == 119)
        cout << "Array is full! Ending input." << endl;

        for (j = 0; j <= i; j++)
        {
            average += scores[j];
        }

        average /= i;

        for (j = 0, k = 0; j < i; j++)
        {
            if (scores[j] < average)
            {
                belowAverage[k] = scores[j];
                k++;
            }
        }

        cout << fixed << setprecision(1) << endl;
        cout << "The average of the scores is: " << average << "." << endl;
        cout << fixed << setprecision(0);
        if (k > 0)
        {
            cout << "The scores below the average were: ";
            for (i = 0; i < k; i++)
            {
                cout << belowAverage[i] << " ";
            }
                    cout << endl;

        }
    }
    else
    {
        cout << "No valid scores were entered." << endl;
    }

    return 0;
}