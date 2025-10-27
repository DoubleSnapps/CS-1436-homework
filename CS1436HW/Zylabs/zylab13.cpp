/* This program finds out how many days have passed in so far in a year. 
    It takes an input of the year, month, and day from the user. It outputs
    the amount of days that have passed, including the "current" day. 
    Input Validation is used to ensure the user enters a month [1-12] and
    a year greater than 0. The days entered by the user are validated to be 
    between [1-Max Days in entered Month].  */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isLeapYear(int);
void getMonthInfo(int, int, string &, int &, bool);
bool getValidDate(int &, int &, int &);
int daysInMonth(int, bool = false);

int main()
{
    int days, month, year, daysPassed;
    string monthName;
    bool leapYear, validDate = false;

    //----------------Function Call----------------

    validDate = getValidDate(month, days, year);
    cout << setfill('0');

    //----------------Result Output----------------

    if (validDate)
    {
        leapYear = isLeapYear(year);
        getMonthInfo(month, days, monthName, daysPassed, leapYear);
        cout << monthName << " " << days << " is day " << daysPassed
            << " of " << setw(4) << year << "." << endl;
    }

    return 0;

}

/*  This function finds data based on given month,
    days in month, and if the year is a leap year. 
    This function assumes that days has previously 
    been validated to ensure (days < month max day).

    Requires: month [1-12] (int)
    Requires: days [1-max days] (int)
    Requires: monthName (string, linked as pass by reference)
    Requires: daysPassed (int, linked as pass by reference)
    Requires: if the year is a leap year (bool)
    Returns: Pass by Refs of monthName and daysPassed.  */
void getMonthInfo(int month, int days, string &monthName, int &daysPassed, bool leapYear)
{

    //----------------Determine monthName----------------

    switch (month)
    {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November";
        break;
    case 12:
        monthName = "December";
        break;
    }

    //----------------Calculate daysPassed----------------

    // Not a fan, but cleanest I cold come up with
    // If month is larger than previous month, add days in prev month
    daysPassed = days;
    daysPassed += ((month > 1) ? daysInMonth(1) : 0);
    daysPassed += ((month > 2) ? daysInMonth(2, leapYear) : 0);
    daysPassed += ((month > 3) ? daysInMonth(3) : 0);
    daysPassed += ((month > 4) ? daysInMonth(4) : 0);
    daysPassed += ((month > 5) ? daysInMonth(5) : 0);
    daysPassed += ((month > 6) ? daysInMonth(6) : 0);
    daysPassed += ((month > 7) ? daysInMonth(7) : 0);
    daysPassed += ((month > 8) ? daysInMonth(8) : 0);
    daysPassed += ((month > 9) ? daysInMonth(9) : 0);
    daysPassed += ((month > 10) ? daysInMonth(10) : 0);
    daysPassed += ((month > 11) ? daysInMonth(11) : 0);

}

/*  This function prompts the user for a date,
    and validates the entered date.

    Requires: month (int, linked as pass by reference)
    Requires: days (int, linked as pass by reference)
    Requires: years (int, linked as pass by reference)
    Returns: if date is valid (bool), along with pass by references. */
bool getValidDate(int &month, int &days, int &year)
{

    bool validDay, validMonth, validYear, leapYear, validDate;
    char ch;

    //----------------User Prompt----------------

    cout << "Enter a date [MM/DD/YYYY]: ";
    cin >> month;
    cin >> ch;
    cin >> days;
    cin >> ch;
    cin >> year;
    cout << endl;

    //----------------Input Validation----------------

    validYear = year > 0;
    validMonth = ((month >= 1) && (month <= 12));
    leapYear = isLeapYear(year);

    // Day must be less than or equal to max days in month, and greater than 0
    validDay = ((days <= daysInMonth(month, leapYear)) && (days > 0));

    validDate = (validMonth && validDay && validYear);

    //----------------Error Reporting----------------

    if (!validDate)
    {
        cout << setfill('0');

        // Setw(2 or 4) is used to ensure formatting of 0X or 0XXX/00Xx/000X
        cout << "Error: " << setw(2) << month << "/" << setw(2) << days
             << "/" << setw(4) << year << " is not a valid date." << endl;
        validDate = false;
    }

    //----------------Return Validity----------------

    return validDate;
}

/*  This function determines the
    amount of days in a given month
    
    Requires: month as an number (int)
    Requires: if it is leap year (boolean)
    Returns: amount of days (int)   */
int daysInMonth(int month, bool leapDay)
{

    int days = 0;

    // Days are set to max days in year
    switch (month)
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

/*  This function determines
    if a year is a leap year.

    Requires: year (int)
    Returns: if it is a leap year (boolean)   */
bool isLeapYear(int year)
{

    bool leapYear = false;

    // if statements are used for readability

    // Year must be divisible by both 100 and 400
    if (((year % 100) == 0) && ((year % 400) == 0))
    {
        leapYear = true;
    }

    // Year isn't divisible by 100, but is divisible by 4
    if (((year % 100) != 0) && ((year % 4) == 0))
    {
        leapYear = true;
    }

    return leapYear;
}
