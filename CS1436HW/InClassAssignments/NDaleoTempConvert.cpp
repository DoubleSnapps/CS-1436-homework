/*  This program converts temperature between
    celsius and fahrenheit. It takes an input
    of temperature unit and the temperature from
    the user. It outputs the user's temperature
    in the other unit. Input validation is used
    to make sure the user enters either C of F. */

#include<iostream>
#include<iomanip>

using namespace std;

double celsius(double);
double fahrenheit(double);

int main()
{

    double initTemp, convertedTemp;
    char tempUnit;

    //----------------User Prompt----------------   

    cout << "Indicate unit of temperature." << endl;
    cout << "\tFor fahrenheit enter F:" << endl;
    cout << "\tFor celsius enter C:" << endl;
    cin >> tempUnit;
    cout << endl << "Enter the temperature (°" <<  tempUnit << ") : " ;
    cin >> initTemp;

    cout << fixed << setprecision(2);

    //----------------Input Validation and Result Output----------------   

    switch (tempUnit)
    {
    case 'F':
    case 'f':
        convertedTemp = celsius(initTemp);
        cout << initTemp << "°F in celsius is " << convertedTemp << "°C";
        break;
    
    case 'C':
    case 'c':
        convertedTemp = fahrenheit(initTemp);
        cout << initTemp << "°C in fahrenheit is " << convertedTemp << "°F";
        break;

    default:
        cout << "Temperature unit not understood, please try again." << endl;
        break;

    }

    return 0;

}

/* This program converts a fahrenheit to celsius.   
    Requires: fahrenheit (double)
    Returns: celsius (double)   */
double celsius(double fahrenheit)
{
    // 5/9 times the sum of (fahrenheit minus 32)
    return ((5.0/9.0) * (fahrenheit - 32));
}


/* This program converts a celsius to fahrenheit.   
    Requires: celsius (double)
    Returns: fahrenheit (double)   */
double fahrenheit(double celsius)
{
    // 9/5 times celsius plus 32
    return ((9.0/5.0) * celsius + 32);
}