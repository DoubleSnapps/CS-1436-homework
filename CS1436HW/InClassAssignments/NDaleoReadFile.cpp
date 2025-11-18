/*  This function finds if a group of students
    in a class passed. It takes an input of a file, 
    with each line containing student name (string), 
    exam 1, 2, and 3 grades (ints). It then outputs 
    the student info and if they passed or failed (exam avg > 60)   */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    string studentName, passed;
    double exam1, exam2, exam3, i, average;
    ifstream inputFile;

    inputFile.open("InputFile.txt");

    if(inputFile)
    {

        while(inputFile >> studentName >> exam1 >> exam2 >> exam3)
        {
            // student's average exam score
            average = (exam1 + exam2 + exam3) / 3.0;

            // above 60 passed, below 60 failed
            passed = (average > 60) ? "pass" : "fail";

            // output students info
            cout << studentName << " " << exam1 << " " << exam2 << " " << exam3 << " " << passed << endl;
        }

        inputFile.close();

    }

    cout << "Program finished" << endl;

    return 0;

}
