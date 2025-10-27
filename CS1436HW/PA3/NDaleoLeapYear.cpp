/*  This function determines if a year is a leap year,
    and finds the days in a given month. It takes an
    input of month and year from the user. It outputs
    the amount of days in the month, accounting for
    feb.'s leap day. Input validation is used to make
    sure the month is [1-12].   */

#include<iostream>
#include<string>

using namespace std;

bool getLeapYear(int);
int daysInMonth(int, bool);

int main()
{

    int month, days, year;
    bool validMonth, isLeapYear;

    cout << "Enter a month [1-12]: ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year; 
    cout << endl;

    //month must be [1-12]
    validMonth = ((month >= 1) && (month <= 12));

    // Only can calculate days if the month is real
    if(validMonth)
    {
        isLeapYear = getLeapYear(year);
        
        days = daysInMonth(month, isLeapYear);

        cout << days << " days";
    }
    else
    {
        cout << "Month entered does not exist." << endl;
        cout << "Ending the program; Please Try again";
    }

    return 0;

}

/*  This function determines
    if a year is a leap year.
    Requires: year (int)
    Returns: if it is a leap year (boolean)   */
bool getLeapYear(int year)
{

    bool isLeapYear = false;  

    // if statements are used for readability
    
    // Year must be divisible by both 100 and 400
    if(((year % 100) == 0) && ((year % 400) == 0))
    {
        isLeapYear = true;
    }
    // Year isn't divisible by 100, but is divisible by 4
    if(((year % 100) != 0) && ((year % 4) == 0))
    {
        isLeapYear = true;
    }

    return isLeapYear;

}

/*  This function determines the
    amount of days in a given month
    Requires: month as an number (int)
    Requires: if it is leap year (boolean)
    Returns: amount of days (int)   */
int daysInMonth(int month, bool leapDay)
{

    int days = 0;

    switch(month)
    {
        // Jan, Mar, Jul, Aug, Oct, Dec
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
        break;
        // Apr, Jun, Sept, Nov
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
        break;
        // Feb
        case 2:
            //  I didn't want to use a ternary and mix if() and switch() statements
            days = leapDay + 28;
        break;
    }

    return days;

}