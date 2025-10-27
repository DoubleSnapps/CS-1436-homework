/*  This program is a simple menu-based calculator app can preform arithmetic.
    operations on two terms. There is built-in user input validation. The program
    first takes a menu input of either +,-,*, or /, which represent their respective
    arithmetic operations, if division is chosen, the program, will also validate 
    that num2 is not equal to 0. If the entered operation is valid, the program 
    will then take an input of 2 terms. The program finally outputs the result between
    num1, the chosen operation, and num2.    */

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
    double num1, num2, result; 
    char choice; 
    string strChoice;

    //Two flags are used to prevent errors
    bool validChoice = false, isDivisible = true;

    cout << "Choose an arithmetic operation by entering a character:"
         << endl << endl;
    cout << "\t" << "For Addition enter: +" << endl;
    cout << "\t" << "For Subtraction enter: -" << endl;
    cout << "\t" << "For Multiplication enter: *" << endl;
    cout << "\t" << "For Division enter: /" << endl << endl;
    cin >> choice;

    switch(choice)
    {
        case '+':
            strChoice = "addition";
            validChoice = true;
            break;
        case '-':
            strChoice = "subtraction";
            validChoice = true;
            break;
        case '*':
            strChoice = "multiplication";
            validChoice = true;
            break;
        case '/':
            strChoice = "division";
            validChoice = true;
            break;

        default:
            cout << "Error: Input not understood; Try again";
            validChoice = false;
            break;
    }

    // If the user enters a invalid char, this section will be skipped
    if (validChoice)
    {

        cout << "Enter your first term: ";
        cin >> num1;
        
        cout << "Enter your second term: ";
        cin >> num2;

        if (choice == '+')
        {
            result = num1 + num2;
        }
        else if (choice == '-')
        {
            result = num1 - num2;
        }
        else if (choice == '*')
        {
            result = num1 * num2;
        }
        else if (choice == '/' && !(num2 == 0))
        {
            result = num1 / num2;
            isDivisible = true;
        }
        else if (choice == '/' && num2 == 0)
        {
            result = 0;
            isDivisible = false;
        }

        //If the user chooses division and enters 0 as the second term, this will be skipped
        if (isDivisible)
        {
            cout << "\t" << num1 << " " << choice << 
                " " << num2 << " = " << result << endl;
        }
        else
        {
            cout << "Error: Cannot divide by 0" << endl;
        }
        
    }

    return 0;

}