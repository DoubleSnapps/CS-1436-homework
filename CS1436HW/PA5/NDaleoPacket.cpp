#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

string findPacketSize(int);
int findPacketTypeIndex(string);
void writeFileReport(const string[], const int[], const string[]);
bool validateFile(ifstream &, string);

const int SIZE = 6;

int main()
{

    int packetSize[SIZE] = {0}, typeCount[3] = {0}, i, spacing = 10;
    string packetID[SIZE], packetType[SIZE], ofName = "packet_report.txt", ifName = "packet.txt";

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(ifName);

    if (inputFile)
    {

        // get data from each line
        for (i = 0; i < SIZE; i++)
        {
            inputFile >> packetID[i];
            inputFile >> packetSize[i];
            inputFile >> packetType[i];
        }

        inputFile.close();

        outputFile.open(ofName);

        if (outputFile)
        {

            // print packet report header

            outputFile << left;
            outputFile << setw(spacing) << "PacketID";
            outputFile << setw(spacing) << "Type";
            outputFile << setw(spacing) << "SizeCategory";
            outputFile << endl;

            for (i = 0; i < SIZE; i++)
            {

                // increment count of type 
                typeCount[findPacketTypeIndex(packetType[i])]++;

                // add packet info to report

                outputFile << setw(spacing) << packetID[i];
                outputFile << setw(spacing) << packetType[i];
                outputFile << setw(spacing) << findPacketSize(packetSize[i]);
                outputFile << endl;
            }

            // output type summary
            outputFile << endl << "Summary:" << endl;
            outputFile << "TCP: " << typeCount[0] << endl;
            outputFile << "UDP: " << typeCount[1] << endl;
            outputFile << "ICMP: " << typeCount[2] << endl;

            outputFile.close();
        }
        else
        {
            cout << "Error: Output file not opened." << endl;
        }
    }
    else
    {
        cout << "Error: Input file not opened." << endl;
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

    if (inputFile && getline(inputFile, str))
    {
        notEmpty = true;
    }

    inputFile.close();

    return notEmpty;
}

/*  */
int findPacketTypeIndex(string packetType)
{
    int sizeIndex = 0;

    if (packetType == "ICMP")
    {
        sizeIndex = 2;
    }
    else if (packetType == "UDP")
    {
        sizeIndex = 1;
    }
    else if (packetType == "TCP")
    {
        sizeIndex = 0;
    }

    return sizeIndex;
}

/*  */
string findPacketSize(int packetSize)
{
    string sizeCategory = "\0";

    if (packetSize > 1500)
    {
        sizeCategory = "Large";
    }
    else if (packetSize < 500)
    {
        sizeCategory = "Short";
    }
    else
    {
        sizeCategory = "Medium";
    }

    return sizeCategory;
}
