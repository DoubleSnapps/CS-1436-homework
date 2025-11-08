#include <iostream>

using namespace std;

int main()
{

    int i = 0, newlineIteration = 1;

    while (i < 127)
    {
        // ASCII characters from 1-31 are not printable
        if(i > 31) cout << static_cast<char>(i);
        i++;

        if(i == (16 * newlineIteration))
        {
            cout << endl; 
            newlineIteration++;
        }
    }

    return 0;

}