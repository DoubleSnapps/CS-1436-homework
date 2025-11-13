/*  This program generates employees's weekly payrolls. 
    It takes an input of employee number from the user 
    (centennial value of 0), employee's gross pay, 
    state tax rate, federal tax rate, and fica withholdings.
    It outputs a formatted employee payroll with entered 
    data and employee's net pay.   */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void payrollReport(int employeeNumber, double grossPay,
                   double stateTaxRate, double federalTaxRate, double ficaWithholdings);
double getPayrollInfo(string);

int main()
{

    string employeeNumberMsg = "Enter Employee Number (#): \n\tEnter 0 to exit\n",
           grossPayMsg = "Enter Gross Pay in $: ", stateTaxMsg = "Enter State Tax Rate as percentage (20% as 0.2): ",
           federalTaxMsg = "Enter Federal Tax Rate as percentage (20% as 0.2): ", ficaMsg = "Enter fica withholdings in $: ";

    double grossPay, stateTaxRate, federalTaxRate, taxTakeAway, ficaWithholdings, netPay;
    int employeeNumber = 1;

    while (employeeNumber != 0)
    {

        //----------------User Prompts----------------

        employeeNumber = getPayrollInfo(employeeNumberMsg);

        // if user chooses to exit, this wont run
        if (employeeNumber != 0)
        {
            grossPay = getPayrollInfo(grossPayMsg);
            stateTaxRate = getPayrollInfo(stateTaxMsg);
            federalTaxRate = getPayrollInfo(federalTaxMsg);
            ficaWithholdings = getPayrollInfo(ficaMsg);

            taxTakeAway = (grossPay * stateTaxRate) + (grossPay * federalTaxRate);

            //----------------Result Output----------------

            // if money removed from gross pay is greater than gross pay, re-enter
            if (grossPay < (taxTakeAway + ficaWithholdings))
            {
                cout << "Re-Enter data for employee #" << employeeNumber << endl;
            }
            else
            {
                payrollReport(employeeNumber, grossPay, stateTaxRate, federalTaxRate, ficaWithholdings);
            }
        }
    }
}

/*  This function generates a given employees weekly payroll.
    Requires: employee's number (int)
    Requires: employee's gross pay (double)
    Requires: state tax rate (double)
    Requires: federal tax rate (double)
    Requires: fica withholdings (double)    */
void payrollReport(int employeeNumber, double grossPay,
                   double stateTaxRate, double federalTaxRate, double ficaWithholdings)
{

    double netPay;
    char ch;

    // net pay is gross pay minus state and federal taxes and fica withholdings
    netPay = grossPay - ((grossPay * stateTaxRate) + (grossPay * federalTaxRate) + ficaWithholdings);

    cout << fixed << setprecision(2);

    cout << endl
         << "Employee #" << employeeNumber << " Weekly Payroll" << endl;
    cout << "-----------------" << endl;
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "State Tax Rate: " << (stateTaxRate * 100) << "%" << endl;
    cout << "Federal Tax Rate: " << (federalTaxRate * 100) << "%" << endl;
    cout << "Fica Withholdings: $" << grossPay << endl;
    cout << "-----------------" << endl;
    cout << "Net Pay: $" << netPay << endl
         << endl;

    cout << "Press any key to continue. ";
    cin >> ch;
}

/*  This function gets a non-negative
    number for the employees payroll.
    Requires: message to prompt user (string)
    Returns: users answer, ensured to be >= 0 (double)  */
double getPayrollInfo(string message)
{
    double number = 0;
    bool validNumber = true;

    do
    {
        cout << ((!validNumber) ? "Invalid Number" : "");

        cout << message;
        cin >> number;

        validNumber = (number >= 0);

    } 
    while (!validNumber);

    return number;
}
