#include <iostream>

using namespace std;

int main()
{
    int i = 0, j = 0;

    while (i < 10)
    {
        i++;

        for (j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    i = 0;

    while (i < 10)
    {

        for (j = 10; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;

        i++;
    }

    return 0;

}