/*   This program calculates the costs of loan, given a payment length, 
     loan size, and loan rate. The program takes an input of loan size (usd), 
     loan length (months), and loan interest rate (yearly) from the user.
     The program then outputs the monthly payment, the total paid back,
     and the total interest paid on the loan.   */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

     // Width offsets are defined for easier reading of complex cout statements.
    const int INITIAL_OFFSET = 10, SECONDARY_OFFSET = 20;

     // Strings are defined for easier reading of complex cout statements.
    string loanAmtStr = "Loan Amount:", monthlyRateStr = "Monthly Interest Rate:",
          numOfPaymentsStr = "Number of Payments:", monthlyPaymentStr = "Monthly Payment:",
               amountPaidStr = "Amount Paid Back:", interestPaidStr = "Interest Paid:";

     double interestRate, payments, loanSize,
          monthlyCost, totalPaid, interestPaid;


    // User Prompts

    cout << "Enter your loan's length of months: ";
    cin >> payments;
    cout << endl;

    cout << "Enter your loan's yearly interest rate: ";
    cin >> interestRate;

    // Divide by 100 to convert to percent, divide yearly rate by 12 to get monthly rate.
    interestRate = (interestRate / 100.0) / 12.0;

    cout << endl;

    cout << "Enter the amount of dollars loaned: ";
    cin >> loanSize;
    cout << endl;


    // Cost Calculations 

    /*  The interest rate is multiple by the rate + 1 to the power of the payments,
        then divided by the rate + 1 to the power of the payments, which the result 
        is subtracted by one, and then multiplied by loan size.    */
     monthlyCost = (interestRate * pow((1 + interestRate), payments)) /
          (pow((1 + interestRate), payments) - 1) * loanSize;


    // Total cost is monthlyCost * months (payments).
    totalPaid = monthlyCost * payments;
    

    // Interest accrued over time.
    interestPaid = (totalPaid - loanSize);


    // Information Output 

    // Right alignment, fixed variables, and precision declared.
    cout << right << fixed << setprecision(2);

    /*    Left alignment is used for all title strings,
          as each has a different length, using left alignment 
          lets us declare that 20 spaces must be "reserved" for the string. 
          --
          Right alignment is then declared when printing '$' or values, 
          so that they can be spaced together.     */

    cout << left << setw(SECONDARY_OFFSET) << loanAmtStr
          << right << setw(INITIAL_OFFSET) << "$"
          << setw(INITIAL_OFFSET) << loanSize << endl;

    cout << setprecision(0);

    cout << left << setw(SECONDARY_OFFSET) << monthlyRateStr
         << right << setw(SECONDARY_OFFSET - 3) << (interestRate * 100) << "%" << endl;

    cout << left << setw(SECONDARY_OFFSET) << numOfPaymentsStr
         << right << setw(SECONDARY_OFFSET) << payments << endl;

    cout << setprecision(2);

    cout << left << setw(SECONDARY_OFFSET) << monthlyPaymentStr
         << right << setw(INITIAL_OFFSET) << "$"
         << setw(INITIAL_OFFSET) << monthlyCost << endl;

    cout << left << setw(SECONDARY_OFFSET) << amountPaidStr
         << right << setw(INITIAL_OFFSET) << "$"
         << setw(INITIAL_OFFSET) << totalPaid << endl;

    cout << left << setw(SECONDARY_OFFSET) << interestPaidStr
         << right << setw(INITIAL_OFFSET) << "$"
         << setw(INITIAL_OFFSET) << interestPaid << endl;


    return 0;

}