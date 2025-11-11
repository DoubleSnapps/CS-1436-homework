#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isPalindrome(string numStr);
int main()
{

    // int bacteria = 50, i = 1, hour;
    // cout << "Enter hour: " << endl;
    // cin >> hour;
    // while(i<=hour)
    // {
    //     bacteria *= 2;
    //     cout << "Hour " << i << " " << bacteria;
    //     i++;
    // }



    // palindrome = isPalindrome("121");
    //         cout << (palindrome ? "true" : "false") << endl;
    // palindrome = isPalindrome("35435");
    //         cout << (palindrome ? "true" : "false")<< endl;
    //         palindrome = isPalindrome("78987");
    //         cout << (palindrome ? "true" : "false")<< endl;
    //         palindrome = isPalindrome("10000");
    //         cout << (palindrome ? "true" : "false")<< endl;
}

bool isPalindrome(string numStr)
{
    string revNum;
    int i = 0, len;
    len = numStr.length();
    while (i < len)
    {
        revNum += numStr.at(len - (1 + i));
        i++;
    }
    cout << numStr << " " << revNum;

    return (revNum == numStr);
}
