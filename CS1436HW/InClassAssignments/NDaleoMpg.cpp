/*  This program caculates total miles a car can drive on a full tank of gas.
    The user is prompted for their car's total gallons and miles per gallon (mpg).
    The program outputs the calculated total range of the car.  
*/

#include<iostream>

using namespace std;

int main()
{

    double gallons, milesPerGal, possibleMiles;

    cout << "Enter the total gallons of gas the car can hold: ";
    cin >> gallons;
    cout << endl;

    cout << "Enter the car's miles per gallon: ";
    cin >> milesPerGal;
    cout << endl;

    possibleMiles = gallons * milesPerGal;

    cout << "The car is able to drive " << possibleMiles << " miles.";

    return 0;

}