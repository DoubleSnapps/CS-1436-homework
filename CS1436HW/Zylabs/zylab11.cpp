/*  This program calculates the volume and surface area of a
    sphere given its radius. It takes an input of radius from
    the user, and will output a formatted result of the volume
    and surface area. This program utilizes two functions, findVolume
    and findSurfaceArea to calculate these values. Data validation
    is utilized to make sure radius is greater than 0.   */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double const PI = acos(-1);

double findVolume(double);
double findSurfaceArea(double);

int main()
{
    double radius, volume, surfaceArea;
    bool validRadius = true;

    // User Prompt

    cout << "\t\tSphere Calculator" << endl
         << endl;

    cout << "Please enter the radius of a sphere: ";
    cin >> radius;
    cout << endl;

    // Input Validation

    validRadius = ((radius > 0) ? true : false);

    // Result Output

    // Radius must be greater than 0
    if (validRadius)
    {
        volume = findVolume(radius);
        surfaceArea = findSurfaceArea(radius);

        cout << fixed << setprecision(3);
        cout << "A sphere with a radius of " << radius << " has:" << endl;
        cout << "\tVolume = " << volume << " cubic units." << endl;
        cout << "\tSurface area = " << surfaceArea << " square units." << endl;
    }
    else
    {
        cout << "Error, the radius must be greater than 0!" << endl;
    }

    return 0;

}

/*  This function calculates and returns volume
    Takes parameter radius of the type double   */
double findVolume(double radius)
{

    // 4/3 multiplied by PI and radius cubed
    return ((4.0 / 3.0) * PI * pow(radius, 3));

}

/*  This function calculates and returns surface area
    Takes parameter radius of the type double   */
double findSurfaceArea(double radius)
{

    // 4 multiplied by PI and radius squared
    return (4.0 * PI * pow(radius, 2));

}