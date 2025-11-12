/*  This file saves a variety of strings to a .txt
    file as their ASCII codes, i.e, each character
    in a string is saved as its ASCII index. This
    program takes an input of the file name from
    the user. Input(s) for strings are taken, and
    a centennial (exit) value of "123" is specified.
    The program outputs a file with the ASCII values
    of the characters of the users entered string. */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

    string message = "\0", fileName = "\0";
    int i = 0;

    cout << "Enter the name of the output file." << endl;
    cin >> fileName;
    cin.ignore();

    // create output file w/ users file name
    ofstream outputFile(fileName);

    // only runs if the file was successfully opened
    if (outputFile)
    {

        //  exit value of "123"
        while (message != "123")
        {

            /*  if the user has entered more than 1
                string, ask for another instead of a */
            cout << "Enter " << ((i > 0) ? "another" : "a");
            cout << " word or phrase [enter 123 to end input]." << endl;
            getline(cin, message);

            // only save to file if not exit
            if (message != "123")
            {

                for (i = 0; i < message.length(); i++)
                {
                    // this is just the second derivitive of a string
                    outputFile << static_cast<int>(message.at(i)) << " ";
                    cout << static_cast<int>(message.at(i)) << " ";
                }

                outputFile << endl;
            }
        }

        // close file once loop ends
        outputFile.close();
    }
    else
    {
        cout << endl
             << "Error, unable to open the output file." << endl;
    }

    return 0;
}