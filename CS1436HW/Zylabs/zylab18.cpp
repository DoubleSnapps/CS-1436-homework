/*  This program display's a set of store's
    sales numbers. It takes an input of a file,
    with each line containing a store # (int), 
    and then the sales # (double). It output's 
    the stores numbers and their sales numbers, 
    along with a graph of each 1k sales.    */

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

void storeReport(int, double);
void printSalesGraph(double);
bool validateFile(ifstream&, string);

int main()
{

    unsigned int storeNumber;
    double storeSales;
    string fName, line;
    bool notEmpty;

    ifstream inputFile;

    cout << "Enter the name of the file that contains the sales data.";
    cout << endl;
    cin >> fName;
    cout << endl;   

    notEmpty = validateFile(inputFile, fName);
    
    inputFile.open(fName);

    // if file is opened, but is empty
    if(inputFile && !notEmpty)
    {
         cout << "Unable to read sales record from the file." << endl;
    }
    // if file is open and not empty
    else if(inputFile)
    {
        cout << endl << "\tSALES BARCHART - Each $ represents $1,000 in sales." << endl << endl;

        while(inputFile >> storeNumber >> storeSales)
        {
            storeReport(storeNumber, storeSales);
        }
    }
    // if file is not open
    else
    {
        cout << "Error, unable to open the input file." << endl;
    }

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

/*  This function prints a stores sales report.
    Requires: store number (int)
    Requires: store's sales (double)    */
void storeReport(int storeNumber, double storeSales)
{
    cout << right << fixed << setprecision(0);
    cout << "Store Number:" << setw(5) << storeNumber;
    cout << setprecision(2);
    cout << "\t" << "Sales:" << setw(10) << storeSales;
    cout << "\t";

    printSalesGraph(storeSales);

}


/*  This function prints an '$' for
    each 1000 dollars of sales. 
    Requires: sales in usd (double)   */
void printSalesGraph(double sales)
{
    int i, intSales;

    // sales are divided by 1000, and truncated
    intSales = static_cast<int>(sales / 1000);

    // print one $ per 1k sales
    for (i = 0; i < intSales; i++)
    {
        cout << "$";
    }

    cout << endl;

}