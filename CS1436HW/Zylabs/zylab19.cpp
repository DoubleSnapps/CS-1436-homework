    /*  This program counts valid numbers [18-60] 
        from a file. It takes an input of a file,
        with each line containing one number. 
        It outputs the amount of values read,
        the valid amount, invalid amount, average
        of the valid numbers, and a file containing the invalid numbers.  */

    #include <fstream>
    #include <iostream>
    #include <string>
    #include <iomanip>

    using namespace std;

    bool validateFile(ifstream&, string);


    int main()
    {

        double currentValue, values, validValues, invalidValues, averageValidValues;
        bool curValueValid = false;
        string ifName, ofName = "badvalues.txt";
        ifstream inputFile;
        ofstream outputFile;

        currentValue = values = validValues = invalidValues = averageValidValues = 0;

        cout << "Enter the input file name." << endl;
        cin >> ifName;
        cout << endl;

        inputFile.open(ifName);

        // only runs if input file is oopened
        if (inputFile)
        {    

            outputFile.open(ofName);

            while (inputFile >> currentValue)
            {
                values += 1;

                curValueValid = (currentValue >= 18 && currentValue <= 60);

                // if value is valid, add one to valid count, vise versa
                validValues += curValueValid;
                invalidValues += !curValueValid;

                // if value is invalid, add to badvalues.txt
                if(!curValueValid)
                {
                    // set formatting for output file
                    outputFile << fixed << setprecision(3);
                    outputFile << currentValue << endl;
                }
                // if value is valid, add to average 
                else
                {
                    averageValidValues += currentValue;
                }

            }

            // result output

            cout << "Total number of values read: " << values << endl;
            cout << "Valid values read: " << validValues << endl;
            cout << "Invalid values read: " << invalidValues << endl;

            // can only find average if there were any valid values
            if (validValues > 0)
            {
                cout << fixed << setprecision(1);
                averageValidValues /= validValues;
                cout << "The average of the valid numbers read is " << averageValidValues  << "." << endl;
            }
            else
            {
                cout << "The file did not contain any valid values." << endl;
            }


            // close files
            inputFile.close();
            outputFile.close();
            
        }
        else
        {
            cout << "Error, the file \"" << ifName << "\" could not be opened." << endl;
        }

        return 0;
    }

