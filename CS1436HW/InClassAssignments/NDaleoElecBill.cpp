/*  This function calculates the cost of an electrical bill. 
    It takes an input of units of electricity consumed by the user. 
    It outputs the cost of the electric bill. Input validation is 
    used to ensure the user enters a positive value.    */

#include <iostream>

using namespace std;

const double LOW_RATE = 0.5, MID_RATE = 0.75, HIGH_RATE = 1.2;

void calculateBill(int, double &);

int main()
{
    int units;
    double billAmt;

    //----------------User Prompt----------------

    cout << "Enter units of electricity consumed: ";
    cin >> units;
    cout << endl;

    //----------------Result Output----------------

    if (units >= 0)
    {
        calculateBill(units, billAmt);
        cout << "Electricity bill is $" << billAmt;
    }
    else
    {
        cout << "Invalid units entered" << endl;
    }

    return 0;
}

/*  This function calculates the 
    cost of the electrical bill.
    
    Requires: units of electricity (int)
    Requires: cost of bill (double, linked as pass by reference)
    Returns: cost of bill (double) as pass by reference.    */
void calculateBill(int units, double &billAmt)
{

    double rate, surcharge;

    // Rate is $0.5 per unit when unit is [0-100]
    // Rate is $0.75 per unit when unit is (100-200]
    // Rate is $1.2 per unit when unit is (200, ∞)

    if (units <= 100)
    {
        rate = LOW_RATE;
    }
    else if (units <= 200)
    {
        rate = MID_RATE;
    }
    else if (units > 200)
    {
        rate = HIGH_RATE;
    }

    billAmt = rate * units;

    // If bill is over $200, 10% surcharge added

    if (billAmt > 200)
    {
        billAmt *= 1.10;
    }

}