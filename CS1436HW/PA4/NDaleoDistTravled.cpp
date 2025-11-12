/*  This program finds the distance a car 
    traveled in a span of hours, for each 
    hour, when given hours traveled and 
    average speed. It takes an input of 
    hours traveled and average vehicle 
    speed from the user. It then outputs 
    the distance traveled for each hour 
    in the total amount of hours.   */

#include <iostream>

using namespace std;

int main()
{

    double speed, distance;
    int i = 1, time;

    cout << "Enter speed of vehicle (mph): " << endl;
    cin >> speed;

    cout << "Enter hours traveled: " << endl;
    cin >> time;

    if (speed >= 0 && !(time < 1))
    {
        cout << "Miles traveled by Hour" << endl;
        cout << "------------------" << endl;
        while (i <= time)
        {
            cout << i << "\t" << (speed * i);
            cout << endl;
            i++;
        }
    }
    else
    {
        cout << "Invalid values entered; Try again" << endl;
    }

    return 0;
}