/*  This program will take an input of two phrases from the user.
    This program will output the first character of each phrase,
    the concatination of the strings, in both orders, and the 
    middle-most character of aformentioned concatinations.  */

#include <iostream>
#include <string>

using namespace std;

int main() {

    //Strings are assigned value that helps w/ debugging
    string phrase1, phrase2, concatResult;
    phrase1 = phrase2 = concatResult = "Undefined by User";

    //User input
    cout << "Please enter a word or phrase." << endl;
    getline(cin, phrase1);

    cout << "Enter a second word or phrase." << endl;
    getline(cin, phrase2);
    cout << endl;

    //First character of each string
    cout << "The first character of \"" << phrase1 << "\" is: "
        << phrase1.at(0) << endl; 
    
    cout << "The first character of \"" << phrase2 << "\" is: "
        << phrase2.at(0) << endl; 
    cout << endl;

    //Combination of first and second string
    cout << "The second string concatenated after the last character of the first string is:";
    cout << endl << "\t";

    concatResult = phrase1 + phrase2;
    cout << concatResult << endl;

    //Middle-most character is found by dividing the length of the string by 2
    cout << "\t" << "The middle character of this string is: "
        << concatResult.at(concatResult.length()/2) << endl;


    //Combination of second and first string
    cout << "The first string concatenated after the last character of second string is:";
    cout << endl << "\t";

    concatResult = phrase2 + phrase1;
    cout << concatResult << endl;

    //Middle-most character is found by dividing the length of the string by 2
    cout << "\t" << "The middle character of this string is: "
        << concatResult.at(concatResult.length()/2) << endl;

    return 0;

}