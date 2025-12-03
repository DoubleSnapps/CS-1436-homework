#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int LENGTH = 6;


int main()
{


    int packetID[LENGTH] = {0}, packetSize[LENGTH] = {0};
    string packetType[LENGTH] = {0}, packetSizeCat[LENGTH] = {0};

    string ifName = "packet.txt", ofName = "packet_report.txt";
    int i, tcpCount, udpCount, icmpCount;

    ifstream inputFile;
    ofstream outputFile;

    i = tcpCount = udpCount = icmpCount = 0;

    inputFile.open(ifName);

    if (validateFile(inputFile, ifName))
    {

        // get data from each line
        for (i = 0; i < LENGTH; i++)
        {
            inputFile >> packetID[i];
            inputFile >> packetSize[i];
            inputFile >> packetType[i];
        }

        // determine if each packet is small, medium, or large
        for (i = 0; i < LENGTH; i++)
        {

            if (packetSize[i] > 1500)
            {
                packetSizeCat[i] = "Large";
            }
            else if (packetSize[i] < 500)
            {
                packetSizeCat[i] = "Short";
            }
            else
            {
                packetSizeCat[i] = "Medium";
            }

        }


        outputFile.open(ofName);

        if (outputFile)
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
void determinePacketSize(int packetSize[LENGTH], int &packetSizeCat[LENGTH])
{
for (int i = 0; i < LENGTH; i++)
        {

            if (packetSize[i] > 1500)
            {
                packetSizeCat[i] = "Large";
            }
            else if (packetSize[i] < 500)
            {
                packetSizeCat[i] = "Short";
            }
            else
            {
                packetSizeCat[i] = "Medium";
            }

        }


}