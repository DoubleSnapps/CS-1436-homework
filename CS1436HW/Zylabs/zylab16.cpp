/*  This program print a triangle of numbers,
    starting at a user entered digit. It takes
    an input of a single digit integer. It then
    outputs the digit, and all following lesser
    digits, starting a new line at 0, and decreasing
    the user digit by 1 until only 0 is printed.  */

#include <iostream>

using namespace std;

int main()
{

    int num, i = 0;
    bool validNum = true;

    do
    {
        if (!validNum)
            cout << "Error, " << num << " is not a single decimal digit." << endl;
        cout << "Enter a decimal digit: ";
        cin >> num;

        validNum = (num >= 0 && num <= 9);
    }
    while (!validNum);

    // runs while num is >= to 0
    while (num >= 0)
    {

        for (i = num; (i <= num) && (i >= 0); i--)
        {
            cout << i;
        }

        // new line is only printed once i < 0
        cout << endl;

        num--;
    }

    return 0;
}
