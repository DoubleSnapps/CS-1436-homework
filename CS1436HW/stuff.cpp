#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    string fileName = "hello";

    ofstream outputFile;

    outputFile.open(fileName + ".txt");

    outputFile << 3 << endl;

    outputFile.close();


}

