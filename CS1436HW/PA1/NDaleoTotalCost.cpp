/*  Using a pre-defined meal cost, tax rate, and tip percentage variables,
    this program calculates the total cost of a meal, along with the added costs,
    and outputs them to the user. It requires no inputs. */

#include<iostream>

using namespace std;

int main() {

    const float COST = 29.12, TAX_RATE = 0.0825, TIP_RATE = 0.15;

    float tax = COST * TAX_RATE;
    float tip = COST * TIP_RATE;

    //the total float is the added cost of food, tax, and tip
    float total = COST + tax + tip;

    cout << "The total bill is " << "$" << total << endl; 
    cout << "\t" << "The sales tax is " << "$" << tax << endl; 
    cout << "\t" << "The tip amount is " << "$" << tip << endl;
    cout << "\t"<< "The meal cost is " << "$" << COST << endl; 

    return 0;
}
