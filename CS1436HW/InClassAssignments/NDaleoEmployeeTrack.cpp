/*  This program determines if employee's have
    met an average sale figure. It takes an input
    of a file, with each line having an employee name 
    followed by 3 separate sales figures. If the average 
    of an employees sales figures is below 5000, they 
    are saved to an output file. This program outputs 
    data for each employee, and saves the bad employees 
    to a file.  */

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

bool validateFile(ifstream&, string);

int main()
{

    ifstream inputFile;
    ofstream outputFile;

    double sales1, sales2, sales3, averageSales;

    string employeeName, iFName = "Employees.txt", oFName = "SalesReport.txt", targetMet;

    sales1 = sales2 = sales3 = averageSales = 0;

    outputFile.open(oFName);

    // if both files are open, and the input file is not empty
    if(validateFile(inputFile, iFName) && outputFile)
    {

        inputFile.open(iFName);

        // get name, then the 3 sales figures
        while(inputFile >> employeeName >> sales1 >> sales2 >> sales3)
        {

            averageSales = (sales1 + sales2 + sales3) / 3.0;
            targetMet = (averageSales > 5000) ? "Target Met" : "Target not Met";

            cout << employeeName << "\t" << sales1 << "\t" 
                << sales2 << "\t" << sales3 << "\t" << averageSales << "\t" << targetMet << endl;

            // save employee's name, avg sales fig if they did not meet the target
            if(averageSales < 5000)
            {
                outputFile << employeeName << "\t" << averageSales << "\t" << targetMet << endl;
            }

        }

        inputFile.close();
        outputFile.close();

    }

    return 0;

}



/*  This function validates that a read file 
    is not empty. File should not be open
    before function is called.
    Requires: input file (ifstream, pass by reference)
    Returns: if the file is not empty (bool)*/
bool validateFile(ifstream &inputFile, string fName)
{
    bool notEmpty = false;
    string str = "\0";

    inputFile.open(fName);

    if(inputFile && getline(inputFile, str))
    {
        notEmpty = true;
    }

    inputFile.close();

    return notEmpty;

}