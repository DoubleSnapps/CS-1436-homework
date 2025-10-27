/*  This program converts an amount of usd to the euro and yen currencies.
    It takes no inputs from the user, and provides no outputs.  */

#include <iostream>

using namespace std;

int main()
{

    // Provided values are used rather than latest values
    const double EURO_TO_USD = 0.74, YEN_TO_USD = 98.93;
    double dollars, euros, yen;

    dollars = 1;

    /*  Currencies are found by multiplying
        dollars by the respective conversion ratio. */
    euros = dollars * EURO_TO_USD;

    yen = dollars * YEN_TO_USD;

    return 0;
    
}