/*  This program shows the user equivent celsius temperature
    for an entered fahrenheit temperature. This program takes
    an input of fahrenheit. It outputs the equivalent celsius
    value for the entered temperature, plus 4 degrees fahrenheit,
    until the temp is greater than 120F. Input validation is used
    to check that entered temp is less than 120F*/

#include<iostream>
#include<iomanip>

using namespace std;

double toCelsius(double);

int main()
{

    double celsius, fareheight; 
    bool validTemp;

    //----------------User Input----------------

    cout << "Enter a Fahrenheit temperature of 120 or lower: ";
    cin >> fareheight;
    cout << endl;

    //----------------Input Validation----------------

    validTemp = (fareheight <= 120);

    //----------------Table Output----------------

    if(validTemp)
    {
        cout << "|Fahrenheit| Celsius|" << endl << fixed << setprecision(1) << right; 
    }

    //fareheight must be less than 120 
    while(fareheight <= 120)
    {
        celsius = toCelsius(fareheight);

        cout << "|" << setw(10) << fareheight << "|";
        cout << setw(8) << celsius << "|";
        cout << endl;

        //increment by 4
        fareheight += 4;

    }

}

/* This program converts a fahrenheit to celsius.   
    Requires: fahrenheit (double)
    Returns: celsius (double)   */
double toCelsius(double fahrenheit)
{
    // 5/9 times the sum of (fahrenheit minus 32)
    return ((5.0/9.0) * (fahrenheit - 32));
}
