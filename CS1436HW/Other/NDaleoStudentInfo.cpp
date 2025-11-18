#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void getStudentData(string&, int&, int&, int&);
void writeStudentInfo(ofstream&, string, int, int, int);

int main()
{

    
    const string fName = "students.txt";
    string studentName;
    int exam1, exam2, exam3, entries, i = 0;

    ofstream outputFile;

    cout << "Enter # of students: ";
    cin >> entries;

    outputFile.open(fName);

    if (outputFile)
    {

        for (i = 0; i < entries; i++)
        {

            getStudentData(studentName, exam1, exam2, exam3);

            writeStudentInfo(outputFile, studentName, exam1, exam2, exam3);

        }

        outputFile.close();

    }

    cout << "Program Finished" << endl;

    return 0;

}


void writeStudentInfo(ofstream &outputFile, string studentName, int exam1, int exam2, int exam3)
{
    outputFile << left << setw(10) << studentName << setw(4) << exam1 << setw(4) << exam2 << setw(4) << exam3 << endl;
}

void getStudentData(string &studentName, int &exam1, int &exam2, int &exam3)
{
    cout << "Enter Student's name: ";
    cin >> studentName;
    cout << "Enter " << studentName << "'s exam 1 grade: ";
    cin >> exam1;
    cout << "Enter " << studentName << "'s exam 2 grade: ";
    cin >> exam2;
    cout << "Enter " << studentName << "'s exam 3 grade: ";
    cin >> exam3;
}