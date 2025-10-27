/*  This program finds the sum of two pseudo-random numbers
    No inputs are needed. The program outputs a formatted 
    addition equation of the generated numbers and their sum.   */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{

    int randNum1, randNum2, randSum;

    // srand is called get timestamps so different seeds can be used for pseudo-random numbers
    srand(time(0));

    // A modulus operation of 100000 is preformed to restrict numbers to [0-99999]
    randNum1 = (rand() % 100000);

    randNum2 = (rand() % 100000);

    randSum = randNum1 + randNum2;

    cout << right;

    // First two lines are aligned w/ respect to the end of the line
    cout << setw(6) << randNum1 << endl;
    cout << "+" << setw(5) << randNum2 << endl;
    cout << "------" << endl;

    cout << setw(6) << randSum << endl;

    return 0;
    
}