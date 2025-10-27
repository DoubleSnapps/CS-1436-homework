/*  This program calculates the distance to origin of a sound,
    given the gas it travels through, and time it was heard
    after occurrence. It takes an input of time since occurrence
    from the user and the type of gas. It outputs the distance of
    the origin location. Input validation is utilized to ensure an
    acceptable gas type, and a time value within [0-30] seconds.   */

#include<iostream>
#include<iomanip>

using namespace std;

double const CARBON_DIOXIDE_MPS = 258.0, 
    AIR_MPS = 331.5, HELIUM_MPS = 972.0, 
    HYDROGEN_MPS = 1270.0;

bool validateGas(char);
double getGasSpeed(char);

int main()
{
    
    char gas;
    double time, distance;
    bool validGas, validTime;

    //----------------User Prompt----------------

    cout << "Enter the gas the sound was heard in:" << endl << endl;
    cout << "\tFor Carbon Dioxide enter C: " << endl;
    cout << "\tFor Air enter A: " << endl;
    cout << "\tFor Helium enter E: " << endl;
    cout << "\tFor Hydrogen enter H: " << endl;
    cin >> gas;

    cout << "Enter the time, in seconds, when the sound was heard: " << endl;
    cin >> time;

    //----------------Input Validation----------------

    validTime = (time > 0 && time <= 30);
    validGas = validateGas(gas);

    //----------------Result Output----------------

    if(validGas && validTime)
    {

        cout << fixed << setprecision(3);

        // speed = distance/time, so distance = speed * time
        distance = time * getGasSpeed(gas);

        cout << "It took " << time << " seconds for the sound to travel " << distance << " meters.";
    }
    else
    {
        cout << "Either Gas or Time entered was invalid." << endl;
        cout << "Ending the program; Please Try again";
    }    

}

/*  Checks if the gas is a valid choice
    Requires: gas to validate (char)
    Returns: the gas's validity (boolean)   */
bool validateGas(char gas)
{
    bool validGas = false;


    // Case insensitive
    switch(gas)
    {
        case 'C':
        case 'A':
        case 'E':
        case 'H':
        case 'c':
        case 'a':
        case 'e':
        case 'h':
        validGas = true;
        break;
    }

    return validGas;

}

/*  Correlates the chosen gas to its sound travel mps
    Requires: the chosen gas (char)
    Returns: the mps of the gas (double)   */
double getGasSpeed(char gas)
{
    double speed = 0;

    switch(gas)
    {
        case 'C':
        case 'c':
            speed = CARBON_DIOXIDE_MPS;
            break;
        case 'A':
        case 'a':
            speed = AIR_MPS;
            break;
        case 'E':
        case 'e':
            speed = HELIUM_MPS;
            break;
        case 'H':
        case 'h':
            speed = HYDROGEN_MPS;
            break;
    }

    return speed;

}
