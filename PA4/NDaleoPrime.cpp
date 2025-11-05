#include <iostream>

using namespace std;

bool isPrime(int);
void printPrime(int);

int main()
{

    // the entered arguments are evaluated to be prime numbers or not
    printPrime(1);
    printPrime(2);
    printPrime(3);
    printPrime(4);
    printPrime(5);
    printPrime(8);
    printPrime(11);
    printPrime(24);
    printPrime(346);
    printPrime(457);
    printPrime(997);

    return 0;

}

/*  This program prints 
    if a number is prime
    or not.
    Requires: number (int)  */
void printPrime(int num)
{
    bool prime;

    prime = isPrime(num);

    cout << num << " is ";

    if (!prime)
    {
        cout << "not ";
    }

    cout << "a prime number." << endl;
}

/*  This function determines if a number is prime or not.
    Requires: number (int)
    Returns: if it is prime (bool)  */
bool isPrime(int num)
{

    int i = 1, divisors = 0;
    bool divisible, prime;

    while (i <= num)
    {
        // if num/i gives no remainder, i is a factor of num
        divisible = ((num % i) == 0);

        // if true, one will be added to the total count of divisors
        divisors += divisible;

        i++;
        
    }

    // if num only has 2 divisors, (1 and itself), it is prime
    prime = (divisors == 2);

    return prime;

}