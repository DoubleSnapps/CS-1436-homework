/*  This function sorts through a system log to extract 
    errors. It takes an input of a "System.log" file, 
    with 3 strings per line, denoting severity level, 
    module, and message. It outputs a SystemErrors log 
    file that contains ERROR level severity messages from 
    the input file. */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    int spacing = 10;
    string ofName = "SystemErrors.log", ifName = "System.log", severity, module, errorMessage;

    ifstream inputFile;
    ofstream outputFile;

    // open file(s)
    inputFile.open(ifName);
    outputFile.open(ofName);

    // runs while outputFile is open and inputFile is not empty
    while(outputFile && (inputFile >> severity))
    {

        inputFile >> module >> errorMessage;

        // if severity level is error, save the log report to system errors file
        if(severity == "ERROR")
        {
            outputFile << left;
            outputFile << setw(spacing) << severity;
            outputFile << setw(spacing) << module;
            outputFile << setw(spacing) << errorMessage;
            outputFile << endl; 
        }

    }

    // close file(s)
    inputFile.close();
    outputFile.close();


    return 0;

}