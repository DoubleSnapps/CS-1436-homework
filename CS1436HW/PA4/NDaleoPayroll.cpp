#include <iostream>
#include <string>

using namespace std;



int main()
{

    string employeeNumberMsg = "Enter Employee Number: \n\tEnter 0 to exit", 
        grossPayMsg = "Enter Gross Pay: ", stateTaxMsg = "Enter State Tax: ",
            federalTaxMsg = "Enter Federal Tax: ", ficaMsg = "Enter fica withholdings: ", 
                netpayMsg = "Enter Net Pay: ";

    double employeeNumber, grossPay, stateTaxRate, federalTaxRate, ficaWithholdings, netPay;

    

    while(employeeNumber != 0)
    {
        
        



    }

    /*Input Validation: Do not accept negative numbers for any of the items entered. Do not
accept values for state, federal, or FICA withholdings that are greater than the gross
pay. If the sum state tax + federal tax + FICA withholdings for any employee is greater
than gross pay, print an error message and ask the user to reenter the data for that
employee.*/


}



/*  This function gets a menu action from the
    user, input validation loop is present.
    Returns: menu action (char)   */
char getAction()
{
    char action;
    bool validAction = true;

    // this loop gets a menu action; runs until a valid action is chosen
    do
    {
        printPrompt(!validAction);
        cin >> action;

        validAction = validateAction(action);

    } 
    while (!validAction);

    return action;
}
double getDoubleInput(string message, bool &entered)
{
    double number = 0;
    bool validNumber = true;

    do
    {

        cout << ((!validNumber) ? "Invalid Number" : "");

        cout << message << endl; 
        cin >> number;

        validNumber = (number >= 0);

    } 
    while(number < 0);

    entered = true;

    return number; 

}

