#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{

    int i=0, strLen;
    string str;

    cout << "enter string";
    getline(cin,str);
    cout << endl;

    strLen = str.length();

    while(i<strLen)
    {
        cout << str.at(i++) << endl;
    }
    
    cout << "over";

}