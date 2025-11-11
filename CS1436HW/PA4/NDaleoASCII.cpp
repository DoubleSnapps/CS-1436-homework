/*  This program outputs the ASCII characters values 0-127. 
    No inputs are taken. The outputs are ASCII values 0-127. */

#include <iostream>

using namespace std;

int main()
{

    int i = 0, newlineIteration = 1;
    char ch;

    while (i < 127)
    {
        // ASCII characters from 1-31 are not printable
        ch = i;
        cout << ch;
        i++;

        /*  if i is equal to 16 times the amount of new line counter,
            print a new line and increment new line counter    */
        if(i == (16 * newlineIteration))
        {
            cout << endl; 
            newlineIteration++;
        }
    }

    return 0;

}