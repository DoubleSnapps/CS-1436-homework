/*  This program determines if a student is eligible to enroll in a certain course path 
    based on their grades. It takes an input of the desired course path,
    math grades, and overall grades from the user. It will then output if the 
    user is eligible or not. Input validation is used to make sure that the 
    user selects an existing course path and the grades are within [0-100]. */

#include <iostream>
#include <string>

using namespace std;

bool isEligible(char, double, double);

int main()
{

    double mathScore, overallScore;
    char coursePath = ' ';
    string coursePathStr;
    bool eligibility = false, validPath = false, validGrade = false;

    // User Prompt

    cout << "Enter the corresponding character for your desired course path." << endl << endl;
    cout << "Science: S" << endl;
    cout << "Commerce: C" << endl;
    cout << "Arts: A" << endl << endl;
    cin >> coursePath;

    cout << "Enter your grade as a number in math: ";
    cin >> mathScore;
    cout << "Enter your overall grade as a number: ";
    cin >> overallScore;

    // Input Validation

    switch (coursePath)
    {
    case 'S':
        validPath = true;
        coursePathStr = "science";
        break;

    case 'C':
        validPath = true;
        coursePathStr = "commerce";
        break;

    case 'A':
        validPath = true;
        coursePathStr = "arts";
        break;

    default:
        validPath = false;
        break;
    }

    //  Both math and overall grades must be [0-100]
    if (mathScore >= 0 && mathScore <= 100 && overallScore >= 0 && overallScore <= 100)
    {
        validGrade = true;
    }

    // Result output

    // Both grades and chosen path must be valid
    if (validGrade && validPath)
    {
        eligibility = isEligible(coursePath, mathScore, overallScore);

        if (eligibility)
        {
            cout << "You are eligible for admission in the " << coursePathStr << " path." << endl;
        }
        else
        {
            cout << "You are not eligible for admission in the " << coursePathStr << " path." << endl;
        }
    }
    else
    {
        cout << "Either chosen path or entered grades were invalid." << endl;
        cout << "Ending the program; Please Try again";
    }

    return 0;

}

bool isEligible(char stream, double mathGrade, double overallGrade)
{
    bool eligibility = false;

    switch (stream)
    {
    case 'S':
        eligibility = ((mathGrade >= 70 && overallGrade >= 65) ? true : false);
        break;

    case 'C':
        eligibility = ((mathGrade >= 60 && overallGrade >= 60) ? true : false);
        break;

    case 'A':
        eligibility = ((overallGrade >= 50) ? true : false);
        break;
    }

    return eligibility;
    
}