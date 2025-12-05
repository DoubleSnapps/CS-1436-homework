#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

string findPacketSize(int);
int findPacketTypeIndex(string);

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

/*  This function converts a packet type to index of the typeCount[] array.
    Requires: packet type (string)
    Returns: 0-2 index 0 = TCP, 1 = TDP, 2 = ICMP (int)*/
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

/*  This function categorizes a packet's 
    size in bytes as small, medium, or large.
    Requires: packet size in bytes (int)
    Returns: packet size category (string)  */
string findPacketSize(int packetSize)
{
    string sizeCategory = "\0";

    if (packetSize > 1500)
    {
        sizeCategory = "Large";
    }
    else if (packetSize < 500)
    {
        sizeCategory = "Small";
    }
    else
    {
        sizeCategory = "Medium";
    }

    return sizeCategory;
}
