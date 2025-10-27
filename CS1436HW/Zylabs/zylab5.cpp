/*  This program converts an angle (degrees) into radians, and finds its sine, cos, and tan values
    The program takes an input of an angle, in degrees, from the user. The program then outputs, in
    a formatted Colum, the angle (degrees), the angle (radians), cos value of the angle, sin value
    of the angle, and tan value of the angle. */

#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

int main()
{

    //PI is set to acos(-1) which is = 3.1415... and so on  
    const double PI = acos(-1);
    const int HEADER_INDENT = 11, VALUE_INDENT = 10; 
    double degAngle, radAngle, cosAngle, sinAngle, tanAngle;

    cout << "Enter an angle in degrees (between 0 and 90): ";
    cin >> degAngle;
    cout << endl;

    //Angle is converted to radians by multiplying by pi over 180
    radAngle = degAngle * (PI / 180.0); 

    cosAngle = cos(radAngle);

    sinAngle = sin(radAngle);

    tanAngle = tan(radAngle);


    //Default
    cout << right;

    //Initial Headers

    cout << setw(HEADER_INDENT) << "Angle|" << setw(HEADER_INDENT) << "Angle|" << endl;

    //Secondary Headers

    //setw() is one less on tan, as it has no |
    cout << setw(HEADER_INDENT) << " Degrees|"
        << setw(HEADER_INDENT) << " Radians|"
        << setw(HEADER_INDENT) << " Cosine|"
        << setw(HEADER_INDENT) << " Sine|"
        << setw(HEADER_INDENT - 1) << "Tangent" << endl;

    //Calculated Values

    //Angle Values
    //VALUE_INDENT 1 less than HEADER_INDENT, as "|" is a separate string
    cout << setw(VALUE_INDENT) << degAngle << "|"
        << setw(VALUE_INDENT) << radAngle << "|";

    //Following values are fixed, and then rounded with 4 significant digits
    cout << fixed << setprecision(4);

    //Sin, Cos, Tan, Results
    cout << setw(VALUE_INDENT) << cosAngle << "|"
        << setw(VALUE_INDENT) << sinAngle << "|" 
        << setw(VALUE_INDENT) << tanAngle << endl; 
    
    return 0;

}