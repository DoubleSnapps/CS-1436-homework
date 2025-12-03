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
    int oldArray[SIZE] = {1,56,3,4};
    int newArray[SIZE] = {0};

    copyArray(oldArray, newArray, SIZE);

    printArray(newArray, SIZE);
    printArray(oldArray, SIZE);

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

    cout << endl << "--------------------------" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;

}