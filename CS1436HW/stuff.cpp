#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void copyArray(int[], int[], int);
void printArray(int[], int);

int main()
{
    const int SIZE = 4;
    string months[SIZE] = {"JAN", "FEB", "MAR", "APR"};

    for(string month : months)
    {
        cout << month << endl;
    }


}

void copyArray(int a[], int b[], int size)
{

    for(int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }

}

void printArray(int a[], int size)
{

    cout << "--------------------------" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;

}