/* This program simply prints out the size of a variety of datatypes, 
    as well as the string class. It requires no input from the user,
    but doing so could streamline the program. 
    It outputs are the sizes (in bytes) of the previously mentioned datatypes.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    short int shInteger;

    int integer;

    long int longInteger;

    long long longLongInteger;

    bool boolean;

    float floatNum;

    double doubleNum;

    long double longDoubleNum;

    char character; 

    string words;

    string sentenceStart = "The size of a ";

    string sentenceEnd = " bytes\n";

    //A single object is used to print the various sizes. 
    //The sentenceStart and sentenceEnd variables are also utilized to remove redundent string li
    cout << sentenceStart << "short integer is " << sizeof(shInteger) << sentenceEnd
        << sentenceStart << "integer is " << sizeof(integer) << sentenceEnd
        << sentenceStart << "long integer is " << sizeof(longInteger) << sentenceEnd
        << sentenceStart << "long long integer is " << sizeof(longLongInteger) << sentenceEnd
        << sentenceStart << "float is " << sizeof(floatNum) << sentenceEnd
        << sentenceStart << "double is " << sizeof(doubleNum) << sentenceEnd 
        << sentenceStart << "long double is " << sizeof(longDoubleNum) << sentenceEnd 
        << sentenceStart << "char is " << sizeof(character) << sentenceEnd 
        << sentenceStart << "bool is " << sizeof(boolean) << sentenceEnd 
        << sentenceStart << "string is " << sizeof(words) << sentenceEnd; 

    return 0;
}