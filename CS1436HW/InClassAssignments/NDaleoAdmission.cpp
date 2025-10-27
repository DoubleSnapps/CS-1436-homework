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

    cout << "Enter the corresponding character for your desired course stream." << endl
         << endl;
    cout << "Science: S" << endl;
    cout << "Commerce: C" << endl;
    cout << "Arts: A" << endl
         << endl;
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
        coursePathStr = "Science";
        break;

    case 'C':
        validPath = true;
        coursePathStr = "Commerce";
        break;

    case 'A':
        validPath = true;
        coursePathStr = "Arts";
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
            cout << "You are eligible to enroll in " << coursePathStr << endl;
        }
        else
        {
            cout << "You are not eligible to enroll in " << coursePathStr << endl;
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