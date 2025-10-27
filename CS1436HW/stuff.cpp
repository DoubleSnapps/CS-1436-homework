#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void thing(int, int);
void thing(double, double);

int main()
{

    thing(1, 1);
    thing(1.0, 1.0);
    // thing(1,1.0);
    // thing(1.0,1);
}
void thing(int a, int b)
{
    cout << "int int";
}
void thing(double a, double b)
{
    cout << "double double";
}