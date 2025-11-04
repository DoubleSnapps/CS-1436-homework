/*  This program allows the user to preform
    a small variety of operations on a given
    integer. An input of a given integer and
    menu selection are taken. The program outputs
    the menu of choices, and the result of the
    menu choices to the user. This program runs
    until the user enters 3 to exit the menu loop.   */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayProductTable(int);
bool isEven(int);
void printMenu();
void operationMenu(int);


int main()
{
    int num;

    //----------------User Prompt----------------

    cout << "Enter an integer: ";
    cin >> num;
    cout << endl;

    //----------------Menu----------------

    operationMenu(num);
}


/*  This function runs a loop
    that displays a menu of
    options for the user to
    preform on their entered integer.   */
void operationMenu(int num)
{

    char selection;
    bool continueExec = true;

    while (continueExec)
    {

        //----------------User Prompt----------------

        printMenu();
        cin >> selection;

        //----------------Menu Execution----------------

        switch (selection)
        {
        case '1':
            displayProductTable(num);
            break;
        case '2':
            cout << num << " is " << (isEven(num) ? "even." : "odd.") << endl;
            break;
        case '3':
            cout << "Exiting Program." << endl;
            continueExec = false;
            break;
        default:
            cout << "Invalid Selection." << endl;
            break;
            
        }
    }
}


/*  This function displays the 
    products of a given number
    and [1-10].
    Requires: num (int) */
void displayProductTable(int num)
{
    int i, product;

    // displays product of num * (i+1) from i = [1-10]
    for (i = 0; i < 10; i++)
    {
        product = num * (i + 1);
        cout << num << " * " << (i + 1) << " = " << product;
        cout << endl;
    }
}


/*  This function determines 
    if a number is even.
    Requires: number (int)
    Returns: if number is even (bool)   */
bool isEven(int num)
{
    bool even;

    // modulus % 2 = 0 becomes true
    even = !(num % 2);

    return even;
}


/*  This function prints the 
    menu choices for the user. */
void printMenu()
{
    cout << "To select, Enter 1, 2, or 3" << endl;
    cout << "\t1. Display multiplication table (1-10)" << endl;
    cout << "\t2. Check if the number is even or odd" << endl;
    cout << "\t3. Exit the program" << endl;
}