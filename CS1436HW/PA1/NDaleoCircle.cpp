/*  This program calculates the radius and area of a circle given diameter.
    This outputs the calculated radius and area. 
    The program uses a predefined diameter value, and requires no user input. */

#include<iostream>
#include<cmath>

using namespace std;

int main() 
{
    double diameter = 16;
    double radius = diameter / 2;

    /*  The area is calculated using the M_PI const from cmath, 
        then multiplied by radius squared */
    double area = M_PI * pow(radius, 2);

    cout << "The radius of the circle is " << radius << " units" << endl;
    cout << "The area of the circle is " << area << " units squared";

    return 0;
}