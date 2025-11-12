#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int getIntInput(string msg);
double getDoubleInput(string msg);


int main()
{
    string itemName = "\0", saleQuality = "\0", fileName = "sales_report.txt";
    int quantitySold = 0;
    double pricePerUnit = 0, totalProfit = 0; 
    char continueLoop = 'y';

    ofstream outputFile(fileName);

    outputFile << "Item Name\tPrice Per Unit\tQuantity Sold\tSale Quality\n"; 

    do
    {

        cout << "Enter Item Name: ";
        getline(cin, itemName);

        pricePerUnit = getDoubleInput("Enter Price per Unit: ");
        quantitySold = getIntInput("Enter Quantity Sold: ");

        totalProfit = quantitySold * pricePerUnit;

        saleQuality = (totalProfit > 50) ? "Good Sale!" : "Low Sale.";

        cout << "Do you want to continue? [y/Y = Yes n/N = no]: ";
        cin >> continueLoop;
        cin.ignore();

        outputFile << left << itemName;
        outputFile << setw(12) << "$" << pricePerUnit << setw(14)
            << quantitySold << setw(14) << saleQuality << endl;

    }
    while(continueLoop == 'y' || continueLoop == 'Y');

    outputFile.close();

    return 0;

}

/*  This function gets a non-negative
    int from the user. It runs
    until a valid (>=1) value is entered.
    Requires: prompt for user (string)
    Returns: user entered value (double)  */
int getIntInput(string msg)
{

    int value = 0;
    bool validValue = true;

    do
    {
        cout << (validValue ? "" : "Invalid Value Entered; Try again\n");
        cout << msg;
        cin >> value;

        validValue = !(value < 1);

    }
    while (!validValue);

    return value;
}

/*  This function gets a non-negative
    int from the user. It runs
    until a valid (>=1) value is entered.
    Requires: prompt for user (string)
    Returns: user entered value (double)  */
double getDoubleInput(string msg)
{

    int value = 0;
    bool validValue = true;

    do
    {
        cout << (validValue ? "" : "Invalid Value Entered; Try again\n");
        cout << msg;
        cin >> value;

        validValue = !(value < 1);

    }
    while (!validValue);

    return value;
}