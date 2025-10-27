/*  This program prints out a simple message to the user
    by using three functions. It takes no inputs from the
    user, and outputs messages by calling three different functions.    */

#include <iostream>
#include <iomanip>

using namespace std;

void greet()
{
    cout << "Welcome user," << endl;
}

void showMessage()
{
    cout << "\tHello World!" << endl;
}

void showGoodbye()
{
    cout << "Goodbye World.";
}

int main()
{
    
    greet();
    showMessage();
    showGoodbye();

    return 0;

}