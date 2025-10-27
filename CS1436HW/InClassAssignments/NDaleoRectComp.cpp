/*  This program compares the area of two rectangles. An input of the 
    length and width of each rectangle is taken from the user, and then
    the comparision of areas is output. This program includes two different
    comparcsin logic blocks, one that relies on conditionals, and another 
    that utilizes if statements.    */

#include <iostream>

using namespace std;

int main()
{

    double rect1Length, rect1Width, rec2Length,
        rec2Width, rect1Area, rect2Area;

    // User Prompts

    cout << "Enter the Length of rectangle one: ";
    cin >> rect1Length;

    cout << "Enter the width of rectangle one: ";
    cin >> rect1Width;

    cout << "Enter the Length of rectangle two: ";
    cin >> rec2Length;

    cout << "Enter the width of rectangle two: ";
    cin >> rec2Width;

    // Area Calculations

    rect1Area = rect1Length * rect1Width;

    rect2Area = rec2Length * rec2Width;

    // Comparison outputs

    /*  To my knowledge, this is the best way show comparison without using if statements,
        or multiple contradictory (english) statements */
    cout << "Rectangle " << ((rect1Area >= rect2Area) + 1)
         << " is larger than or equal to " << ((rect1Area < rect2Area) + 1) << endl;

    // Version using if statements
    if (rect1Area == rect2Area)
    {
        cout << "The area of rectangle 1 and 2 are equal";
    }

    else if (rect1Area > rect2Area)
    {
        cout << "Rectangle 1's area is larger than rectangle 2's";
    }

    else
    {
        cout << "Rectangle 2's area is larger than rectangle 1's";
    }

    return 0;

}