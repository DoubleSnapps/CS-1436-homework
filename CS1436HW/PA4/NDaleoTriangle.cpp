/*  This program uses for loops to output an 
    asterisk triangle. No inputs are taken. 
    The program outputs the first half, then 
    the second half of the triangle.   */

#include <iostream>

using namespace std;

int main()
{
    int i, j;

    //----------------First Half----------------
    
    // runs 10 times
    for (i = 0; i <= 10; i++)
    {
        // prints j amount of *s, increasing with i
        for (j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    //----------------Second Half----------------

    // runs 10 times
   for (i = 0; i < 10; i++)
    {

        // prints j amount of *s, decreasing with i
        for (j = 10; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;

    }

    return 0;
}