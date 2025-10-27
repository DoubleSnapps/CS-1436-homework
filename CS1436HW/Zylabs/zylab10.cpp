/*  This program preforms a simple addition equation. It takes an input of a 
    addition equation of 2 terms, formatted by the user in equation form. 
    It then outputs the resulting solution from the equation, or an error 
    message if input validation fails.    */

#include <iostream>
#include <string>

using namespace std;

/*  This function returns a given number to its word form using w/ a switch-case.    */
string numToNumString(int number)
{
    string numberStr = "";

    switch (number)
    {
        case 0:
            numberStr = "zero";
            break;
        case 1:
            numberStr = "one";
            break;
        case 2:
            numberStr = "two";
            break;
        case 3:
            numberStr = "three";
            break;
        case 4:
            numberStr = "four";
            break;
        case 5:
            numberStr = "five";
            break;
        case 6:
            numberStr = "six";
            break;
        case 7:
            numberStr = "seven";
            break;
        case 8:
            numberStr = "eight";
            break;
        case 9:
            numberStr = "nine";
            break;
    }

    return numberStr;
    
}

int main()
{
    int num1, num2, sum;
    char ch;
    string num1Str, num2Str;

    bool num1Positive = true, num2Positive = true, 
        num1SingleDigit = true, num2SingleDigit = true, useAddition = true;

    // User Prompt

    cout << "Enter your addition problem in the form 3 + 5" << endl;
    cin >> num1;
    cin.ignore();
    cin >> ch;
    cin.ignore();
    cin >> num2;
    cout << endl;

    // Input Validation

    switch (ch)
    {
        case '+':
            useAddition = true;
            break;
        default:
            useAddition = false;
            break;
    }

    if (num1 >= 10)
    {
        num1SingleDigit = false;
    }
    else if (num1 < 0)
    {
        num1Positive = false;
    }
 

    if (num2 >= 10)
    {
        num2SingleDigit = false;
    }
    else if (num2 < 0)
    {
        num2Positive = false;
    }
  
    // Output

    // Only if num1 & 2 are positive single digits [0-9], and the user input addition
    if (num1SingleDigit && num2SingleDigit && num1Positive && num2Positive && useAddition)
    {
        sum = num1 + num2;
        num1Str = numToNumString(num1);
        num2Str = numToNumString(num2);

        cout << num1Str << " plus " << num2Str << " is " << sum << endl;
    }
    else 
    {
        /* I'm aware the grammar is wrong, but I'm not sure
            if zylabs interprets solve = solvable   */
        cout << "Not solve able" << endl;
    }

}