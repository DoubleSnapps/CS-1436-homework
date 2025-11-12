/*  This program calculates the average rainfall over 
    a period of time. It takes user inputs of period 
    of years, and then rainfall for each month within 
    each year. It outputs the months spanned, total 
    amount of rainfall, and average amount of rainfall. 
    All measurement units are inches.  */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int getIntInput(string);
void reportRainfall(int, double);
double getMonthlyRainfall(double&, string);
string getMonthName(int);

int main()
{

    int years, i = 0, j, months;
    double cumulativeRainfall = 0;
    string yearsMsg = "Enter period of Years: \n\tMust be >= 1\n", currentMonth;

    years = getIntInput(yearsMsg);

    // total months is just 12 times total years
    months = years * 12;

    // runs once per year
    while (i < years)
    {
        cout << endl << "Year " << (i + 1) << endl;

        // runs 12 times per year, or once per month
        for (j = 1; j <= 12; j++)
        {
            currentMonth = getMonthName(j);

            getMonthlyRainfall(cumulativeRainfall, currentMonth);
        }

        i++;  
    }

    reportRainfall(months, cumulativeRainfall);

}

/*  This function reports data about
    rainfall over period of months. 
    Requires: length in months (int)
    Requires: cumulative amount of rainfall (double)    */
void reportRainfall(int months, double cumulativeRainfall)
{
    double averageRainfall = cumulativeRainfall / months;

    cout << "Over a period of " << months << " months:" << endl;
    cout << "\t" << cumulativeRainfall << " Inches of Rain fell." << endl;
    cout << "\tAveraging " << averageRainfall << " Inches of rain per month." << endl;
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

/*  This function gets a monthly
    rainfall total from user. It runs
    until a valid (>=0) value is given.
    After, the monthly total is added to
    cumulative total variable.
    Requires: cumulative amount of rainfall (double, pass by reference).
    Linked: cumulative amount of rainfall (double, pass by reference)
    Returns: user entered value (double)  */
double getMonthlyRainfall(double &cumulativeRainfall, string month)
{

    double monthlyRain = 0;
    bool validRain = true;
    do
    {
        cout << (validRain ? "" : "Invalid Value Entered; Try again\n");
        cout << "Enter total of " << month << "'s rainfall in inches: " << endl;
        cout << "\tMust be >= 0" << endl;
        cin >> monthlyRain;

        // runs while rain is invalid, when rainfall is negative 
        validRain = (monthlyRain >= 0);

    } 
    while (!validRain);

    cumulativeRainfall += monthlyRain;

    return monthlyRain;
}

/*  This function gets the name of a month.
    Requires: month's # (int)
    Returns: name of month (string) */
string getMonthName(int monthNum)
{

    string monthStr = "empty";

    // the poor man's enum

    switch (monthNum)
    {
    case 1:
        monthStr = "january";
        break;
    case 2:
        monthStr = "february";
        break;
    case 3:
        monthStr = "march";
        break;
    case 4:
        monthStr = "april";
        break;
    case 5:
        monthStr = "may";
        break;
    case 6:
        monthStr = "june";
        break;
    case 7:
        monthStr = "july";
        break;
    case 8:
        monthStr = "august";
        break;
    case 9:
        monthStr = "september";
        break;
    case 10:
        monthStr = "october";
        break;
    case 11:
        monthStr = "november";
        break;
    case 12:
        monthStr = "december";
        break;
    }

    return monthStr;
}