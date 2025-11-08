#include <iostream>
#include <string>

using namespace std;



int main()
{

    string employeeNumberMsg = "Enter Employee Number: \n\tEnter 0 to exit", 
        grossPayMsg = "Enter Gross Pay: ", stateTaxMsg = "Enter State Tax: ",
            federalTaxMsg = "Enter Federal Tax: ", ficaMsg = "Enter fica withholdings: ", 
                netpayMsg = "Enter Net Pay: ";

    double employeeNumber = 1, grossPay, stateTaxRate, federalTaxRate, ficaWithholdings, netPay;

    while(employeeNumber != 0)
    {
        



    }



}





double getValidNumber(string message, bool &entered)
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

