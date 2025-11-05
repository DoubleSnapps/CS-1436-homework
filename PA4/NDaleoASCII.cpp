#include <iostream>

using namespace std;

int main()
{

    int i = 0, newlineIteration = 1;

    while (i < 127)
    {
        cout << static_cast<char>(i);
        i++;

        if(i == 16 *  newlineIteration)
        {
            cout << endl; 
            newlineIteration++;
        }
    }

    return 0;

}