#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{

    int i =240;
    do
    {
        cout << i % 10;
        i /= 10;
    } while ((i = 10));
    

}