/*  This program calculates the volume of a cylindrical fuel tank.
    It takes no inputs from the user, and outputs the volume of the
    fuel tank.  */

#include<iostream>
#include<cmath>

using namespace std;

int main() 
{

    const double PI = 3.14159;
    double tankHeight = 4, tankRadius = 4, tankVolume;

    // volume = PI times radius squared times height 
    tankVolume = PI * pow(tankRadius,2) * tankHeight;

    cout << "The volume of the fuel tank is " << tankVolume << " Units Cubed";

    return 0;

}