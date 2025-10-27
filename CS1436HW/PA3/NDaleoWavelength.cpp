/*  This program determines the type of radiation 
    an electromagnetic wavelength produces. It takes
    an input of wavelength in meters from the user.
    It outputs the given type of radiation for the wavelength.  */

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

double const RADIO_MIN = (1e-2), MICROWAVE_MIN = (1e-3),
    INFRARED_MIN = (7e-7), VISIBLE_MIN = (4e-7),
    ULTRAVIOLET_MIN = (1e-8), XRAY_MIN = (1e-11);

string findWavelengthRadiation(double);

int main()
{

    double wavelength;
    string radiation;

    //----------------User Prompt----------------

    cout << "To determine the radiation of a wavelength, enter number in c++ scientific notation." << endl;
    cout << "\tXe±Y, with X and Y being numbers." << endl;
    cout << "Enter wavelength in meters: ";
    cin >> wavelength; 
    cout << endl; 

    //----------------Calculation and Result Output----------------

    radiation = findWavelengthRadiation(wavelength);

    cout << "The wavelength would be " << radiation << "." << endl;
}

/*  This function finds the corresponding radiation
    to a given electromagnetic wavelength. 
    Requires: wavelength (double)
    Returns: radiation type (string)    */
string findWavelengthRadiation(double wavelength)
{
    string radiation = "undefined";
    
    /*  radiation is altered up until it is no longer 
        greater than any of the radiation's minimum value.   */
    if(wavelength < XRAY_MIN)
    {
        radiation = "gamma rays";
    }
    if(wavelength >= XRAY_MIN)
    {
        radiation = "x-rays";
    }
    if(wavelength >= ULTRAVIOLET_MIN)
    {
        radiation = "ultraviolet radiation";
    }
    if(wavelength >= VISIBLE_MIN)
    {
        radiation = "visible light";
    }
    if(wavelength >= INFRARED_MIN)
    {
        radiation = "infrared radiation";
    }
    if(wavelength >= MICROWAVE_MIN)
    {
        radiation = "microwaves";
    }
    if(wavelength >= RADIO_MIN)
    {
        radiation = "radio waves";
    }
  
    return radiation;

}