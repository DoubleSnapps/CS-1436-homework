/*  This program evaluates if a integer is positive, negative or zero.
    It takes a integer input from the user, and outputs if that integer
    is a positive, negative, or zero.   */

#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "Enter any whole number: " << endl;
    cin >> num;

    if (num >= 0) 
    {
        if (num > 0)
        {
            cout << "The number is positive";
        }

        else 
        {
            cout << "The number is zero";
        }

    }

    else 
    {
        cout << "The number is negative";
    }

    return 0;

}