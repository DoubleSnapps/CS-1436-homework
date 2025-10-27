/*  This program calculates the total cost of a sale including a tipped amount. The 
    program will take an input of the initial sale price and user's tipped amount, 
    both in dollars. The program will output a formatted bill for the user which 
    includes the sales price, tip, and total    */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double tip20Percent, tip22Percent, tip25Percent, 
        salePrice, chosenTip, totalCost;

    // Sales Price Prompt

    cout << "Enter the amount of the sale in $: ";
    cin >> salePrice;
    cout << endl;

    // Tip Calculation
    // 20%, 22%, and 25% of the sales price are assigned 
    tip20Percent = salePrice * 0.2;

    tip22Percent = salePrice * 0.22;

    tip25Percent = salePrice * 0.25;

    // Tip Prompt

    cout << fixed << setprecision(2);

    cout << "20% tip: $" << tip20Percent << endl; 
    cout << "22% tip: $" << tip22Percent << endl;
    cout << "25% tip: $" << tip25Percent << endl;
    cout << endl;

    cout << "Enter the amount of the tip in $: ";
    cin >> chosenTip;
    cout << endl;

    //  Sales price plus tip equal the total the user must pay
    totalCost = chosenTip + salePrice;

    // Bill Output

    //Headers are reserved 15 spaces from beginning of string
    cout << left;

    cout << setw(15) << "Sales Amount: " << "$" << salePrice << endl;
    cout << setw(15) << "Tip Amount: " << "$" << chosenTip << endl;
    cout << setw(15) << "Total: " << "$" << totalCost << endl;

    return 0;

}