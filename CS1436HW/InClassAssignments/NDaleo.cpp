/* This program promts the use for an the time in 3 seperate units of hours, minutes, and seconds.
    Using the user's given time, it calculates the time in seconds by converting hours and minutes to seconds,
    and then summing the three values */

#include<iostream>
#include<cmath>

using namespace std;

int main() 
{
    int seconds, minutes, hours;

    //Promt the user
    cout << "Enter the time to complete the task in hours, minutes, and seconds." << endl;

    cout << "Enter the hours: " ;
    cin >> hours; 

    cout << "Enter the minutes: ";
    cin >> minutes; 

    cout << "Enter the seconds: ";
    cin >> seconds; 

    /*  The duration variable is set to the sum of seconds in the hour variable, 
        seconds in the minute variable, and the seconds variable */
    int duration = (hours * pow(60,2)) + (minutes * 60) + (seconds);

    cout << "The duration in seconds is " << duration << ".";

}
