#include<iostream>

using namespace std;

int main()
{

    int i = 0;

    while(i < 127)
    {
        do
        {
            // cout << " hello " << i << endl;
            cout << static_cast<char>(i) << " ";
            i++;
        }
        while((static_cast<double>(i)/16) != 1);
        if((static_cast<double>(i)/16) != 1){cout << endl;}
    }


}