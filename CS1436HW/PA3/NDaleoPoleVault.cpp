/*  This program orders a pole vaulter's best three vaults. 
    It takes an input of the vaulter's name along with their
    3 best vault heights, and the dates of those heights.
    This program outputs their 3 best heights, ordered from
    highest to shortest. Input validation is used to ensure
    vault height is within [2.0-5.0].   */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void vaultReport(string, double, double, double, string, string, string);

int main()
{

    double height1, height2, height3;
    string vaulterName, date1, date2, date3;
    char ch;
    bool heightRange, firstHighest, secondHighest, thirdHighest;

    heightRange = firstHighest = secondHighest = thirdHighest = false;

    //----------------User Prompt----------------

    cout << "Enter the Pole Vaulter's name: ";
    getline(cin, vaulterName);

    cout << "In any order, enter the Pole Vaulter's best three vaults." << endl
         << endl;

    cout << "Enter the Vault Date in DD/MM/YY format" << endl;
    getline(cin, date1);
    cout << "Enter the respective Vault height in meters: " << endl;
    cin >> height1;
    cin.ignore();

    cout << "Enter the Vault Date in DD/MM/YY format" << endl;
    getline(cin, date2);
    cout << "Enter the respective Vault height in meters: " << endl;
    cin >> height2;
    cin.ignore();

    cout << "Enter the Vault Date in DD/MM/YY format" << endl;
    getline(cin, date3);
    cout << "Enter the respective Vault height in meters: " << endl;
    cin >> height3;
    cin.ignore();

    //----------------Evaluation and Sorting----------------

    // All heights must be within [2-5] meters
    if((height1 >= 2.0 && height1 <= 5.0) && (height2 >= 2.0 && height2 <= 5.0) && (height3 >= 2.0 && height3 <= 5.0))
    {

        // if two values are equal, the value entered earlier gets priority
        if (height1 >= height2 && height1 >= height3)
        {
            firstHighest = true;
        }

        if (height2 > height1 && height2 >= height3)
        {
            secondHighest = true;
        }

        if (height3 > height2 && height3 > height1)
        {
            thirdHighest = true;
        }

        //----------------Result Output----------------

        if (firstHighest)
        {
            if (height2 >= height3)
            {
                vaultReport(vaulterName, height1, height2, height3, date1, date2, date3);
            }
            else
            {
                vaultReport(vaulterName, height1, height3, height2, date1, date3, date2);
            }
        }

        if (secondHighest)
        {
            if (height1 >= height3)
            {
                vaultReport(vaulterName, height2, height1, height3, date2, date1, date3);
            }
            else
            {
                vaultReport(vaulterName, height2, height3, height1, date2, date3, date1);
            }
        }

        if (thirdHighest)
        {
            if (height1 >= height2)
            {
                vaultReport(vaulterName, height3, height1, height2, date3, date1, date2);
            }
            else
            {
                vaultReport(vaulterName, height3, height2, height1, date3, date2, date1);
            }
        }
    }
    else
    {
        cout << "One or more of the heights entered was invalid." << endl;
        cout << "Ending the program; Please Try again";
    }

    return 0;

}

/*  This function outputs the vault heights and dates. 
    Requires: vaulter name (string)
    Requires: vault heights from highest to shortest (double) 
    Requires: corresponding vault dates from highest to shortest (string)
    Returns: nothing  */
void vaultReport(string vaulterName, double highest, double middle, double shortest,
                string highDate, string midDate, string shortDate)
{

    cout << fixed << setprecision(2);

    cout << vaulterName << " achieved their:" << endl;
    cout << "\t1st Hightest Vault of " << highest << "m on " << highDate << endl;
    cout << "\t2nd Hightest Vault of " << middle << "m on " << midDate << endl;
    cout << "\t3rd Hightest Vault of " << shortest << "m on " << shortDate << endl;

}