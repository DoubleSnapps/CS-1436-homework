/*  This program counts the amount of whitespace
    and comma characters in a given sentence. It
    takes an input of a string from the user. It
    outputs the total amount of whitespace and
    period characters present in the text. Input
    validation is used to ensure the user enters
    a non-empty string. */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string getString(string prompt);
bool isCommaOrSpace(char ch);

int main()
{

    unsigned int periodCommaCount = 0, i = 0;
    string userMsg, prompt = "Please enter a line of text.";

    userMsg = getString(prompt);

    // runs until i is equal to the length of the string
    for (i = 0; i < userMsg.length(); i++)
    {
        periodCommaCount += isCommaOrSpace(userMsg.at(i));
    }

    cout << endl << "The entered text contains "
        << periodCommaCount << " commas and space characters.";
}

/*  This function gets a string from 
    the user, ensuring it is not a 
    blank string. 
    Requires: user prompt (string)
    Returns: entered string (string)    */
string getString(string prompt)
{

    string str;

    cout << prompt << endl << endl;
    getline(cin, str);

    /*  if the string is a whitespace/newline 
        character, the user is forced to re-enter
        until correct    */ 
    while (str == "")
    {
        cout << "Error, empty string received." << endl;
        cout << prompt << endl << endl;
        getline(cin, str);
    }

    return str;
}

/*  This function determines
    if a char is either a whitespace
    or comma character.
    Requires: character (char)
    Returns: if it is whitespace or comma (bool)    */
bool isCommaOrSpace(char ch)
{
    bool commaOrSpace;

    commaOrSpace = (ch == ' ') || (ch == ',');

    return commaOrSpace;
}