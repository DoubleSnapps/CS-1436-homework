/*  This program calculates how many calories
    you will burn while running on a treadmill.
    No inputs are taken. The program outputs 
    the calories burned every 5 minutes, 
    until 30 minutes.   */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double TREADMILL_BURN_RATE = 3.6;

double getBurnedCalories(int, double&);

int main()
{

    int minutes = 0;
    double calBurned = 0;

    cout << "Running on a treadmill, you will have burned: " << endl;

    while (minutes <= 30)
    {
        getBurnedCalories(minutes, calBurned);

        // true when minutes % 5 == 0
        if (!(minutes % 5) && minutes > 0)
        {
            cout << "\t" << calBurned << " calories in " << minutes  << " minutes" << endl;
        }

        minutes++;
    }

    return 0;

}

/*  This function calculates the amount of calories
    burned on a treadmill in a given set of minutes.
    Requires: minutes (int)
    Requires calories burned (double, linked as pass by reference)s
    Returns: calories burned (double, return statement and pass by ref.)   */
double getBurnedCalories(int minutes, double& calBurned)
{
    calBurned = minutes * TREADMILL_BURN_RATE;

    return calBurned;
}