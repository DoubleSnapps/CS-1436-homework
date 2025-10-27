/*  This program simulates an ATM, with balance checking,
    depositing, and withdrawing capabilities. It takes an
    input of action type (view balance, deposit, or withdraw)
    from the user, as well amount to deposit/withdraw if needed.
    The program outputs the balance, which is edit if the user
    deposits or balances. Input validation is used to make sure
    the user enters an existing action and positive numbers.  */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

char actionType(char);
double deposit(double);
double withdrawal(double);

int main()
{

    char action;
    double balance;
    unsigned int seed;
    bool useTime = false, validAction = false;

    //----------------Rand Generation----------------
    if (useTime)
    {
        srand(time(0));
        balance = rand() % 10001;
    }
    else
    {
        cin >> seed;
        srand(seed);
        balance = rand() % 10001;
    }

    //----------------User Prompt----------------

    cout << "\tATM Menu" << endl << endl;
    cout << "B - Check account balance" << endl;
    cout << "D - Deposit money" << endl;
    cout << "W - Withdraw money" << endl << endl;

    cout << "Enter the letter of your desired transaction: ";
    cin >> action;


    // Makes action case insensitive 
    action = actionType(action);


    //----------------Result Output----------------

    switch (action)
    {
    case 'B':
        validAction = true;
        break;
    case 'W':
        balance = withdrawal(balance);
        validAction = true;
        cout << endl;
        break;
    case 'D':
        balance = deposit(balance);
        validAction = true;
        cout << endl;
        break;

    default:
        cout << "Invalid transaction choice." << endl;
        break;
    }

    if(validAction)
    {
        cout << fixed << setprecision(2) << "Your balance is $" << balance << "." << endl;
    }

    return 0;
}

/*  This function calculates the resulting
    balance of an account after the user
    deposits an amount. Input validation 
    is used.
    Requires: Balance (double)
    Returns: New Balance (double)   */
double deposit(double prevBalance)
{
    double depositAmount, newBalance;

    //----------------User Prompt----------------

    cout << "Enter your deposit amount: ";
    cin >> depositAmount;

    //----------------Input Validation----------------

    if (depositAmount <= 0)
    {
        cout << endl << "Invalid deposit amount." << endl;
        newBalance = prevBalance;
    }
    else
    {
        newBalance = prevBalance + depositAmount;
    }

    return newBalance;
}

/*  This function calculates the resulting
    balance of an account after the user
    withdraws an amount. Input validation 
    is used.
    Requires: Balance (double)
    Returns: New Balance (double)   */
double withdrawal(double prevBalance)
{
    double withdrawalAmount = 0, newBalance;

    //----------------User Prompt----------------

    cout << "Enter your withdrawal amount: ";
    cin >> withdrawalAmount;

    //----------------Input Validation----------------

    if (withdrawalAmount <= 0)
    {
        newBalance = prevBalance;

        cout << endl << "Invalid withdrawal amount." << endl;
    }
    if (withdrawalAmount > prevBalance)
    {
        newBalance = prevBalance;

        cout << endl << "You do not have sufficient funds for this withdrawal." << endl;
    }

    //----------------Result Calculation----------------

    if((withdrawalAmount > 0) && (withdrawalAmount < prevBalance))
    {
        newBalance = (prevBalance - withdrawalAmount);
    }

    return newBalance;
}

/*  This function converts select char letters to 
    their uppercase form to remove case sensitivities.
    Requires: char to convert (char)
    Returns: uppercase of char if applicable, or 'N' (char) */
char actionType(char ch)
{

    char action = 'N';

    switch (ch)
    {
    case 'B':
    case 'b':
        action = 'B';
        cout << endl;
        break;
    case 'D':
    case 'd':
        action = 'D';
        break;
    case 'W':
    case 'w':
        action = 'W';
        break;
    }

    return action;
}