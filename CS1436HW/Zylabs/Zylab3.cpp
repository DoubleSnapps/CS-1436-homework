/*  This program calculates the total amount of time in seconds.
    This program will output the total time in seconds, as well as instructions for the user.
    This program will take an input of time in seconds from the user.
    */

#include<iostream>
#include<cmath>

using namespace std;

int main()
{

    //Seconds per minute is 60, while seconds per hour is 60^2
    const int SEC_PER_MIN = 60, SEC_PER_HOUR = pow(60,2);

    long int seconds, minutes, hours, totalSeconds;


    cout << "This program converts a time entered in seconds to hours, minutes, and seconds." << endl;

    cout << "Please enter a time in seconds: ";
    cin >> totalSeconds;
    cout << endl;

    hours = totalSeconds / SEC_PER_HOUR;
    minutes = (totalSeconds - hours * SEC_PER_HOUR) % SEC_PER_MIN;
    seconds = (totalSeconds - hours * SEC_PER_HOUR) % SEC_PER_MIN; 

    //The total seconds is output to the user, as well as the time values they entered
    cout << totalSeconds << " seconds is:" << endl;
    cout << "       " << hours << " hours" << endl;
    cout << "       " << minutes << " minutes" << endl;
    cout << "       " << seconds << " seconds" << endl;

}
/*



Sample output from a program that passes all tests for one possible set of inputs:

This program converts a time entered in seconds to hours, minutes, and seconds.
Please enter a time in seconds: 3775

3775 seconds is:
        1 hours
        2 minutes
        55 seconds
➜ 


Please notice that there is one tab character before the labels on the output hours, minutes, and seconds.

Use the same prompts and messages as the sample above. Please make careful note of the casing and white space shown.

Failure to follow the requirements for lab lessons can result in deductions, even if you pass the auto-graded tests. 

*/