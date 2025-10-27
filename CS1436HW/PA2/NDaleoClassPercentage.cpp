/*  This program calculates the gender percentages of a classroom from user input.
    This program takes an input of male and female students respectively. It will
    then output the percentage male and female students each account for.   */

#include <iostream>

using namespace std;

int main()
{

    int maleStudents, femaleStudents;

    // totalStudents is a float so the ints get automatically promoted
    float totalStudents, malePercent, femalePercent;

    cout << "Enter the amount male students: ";
    cin >> maleStudents;
    cout << endl;

    cout << "Enter the amount female students: ";
    cin >> femaleStudents;
    cout << endl;

    totalStudents = maleStudents + femaleStudents;

    /*  Percentages are found by dividing students/total,
        and the multiplying by 100 for a whole percentage value */
    malePercent = (maleStudents / totalStudents) * 100;

    femalePercent = (femaleStudents / totalStudents) * 100;

    cout << "The class is " << malePercent << "% male students, and "
         << femalePercent << "% female students";

    return 0;

}