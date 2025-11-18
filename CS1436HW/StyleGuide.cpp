/*  This programs primary purpose is outlined here. Another sentence sometimes
    This program outputs these things. This program asks the user for some 
    inputs sometimes. */

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

// function prototypes dont need parameter names
int meaningFulName(int);

int main()
{

    //Either is fine 
    int x, y, z; 
    int x = 1, y = 1, z = 1;

    string sentence = "just some words im sure";

    //Break up complex statements like this, with increasing indentation
    //Also have a comet on the math in complex equations
    x = (sqrt(y) * pow(z,2) + x)
        * 2 * (sqrt(y) * pow(z,2) + x)
            / 3 * (sqrt(y) * pow(z,2) + x);

    cout << "Words that mean something " << x << " unit of x is important" << endl;
    
    //Always have a cout before a cin so the user can be informed
    //only ever use one cin argument
    cout << "Why dont you say something?";
    cin >> sentence;

    if (0 > 1) 
    {
        //Some code that does some stuff
    } 
    else if (1 < 0) 
    {
        //Some code that does some other stuff
    } 
    else 
    {
        //Some code that does some more other stuff
    }
    
    return 0;

}

/* A comment that defines the purpose of a function, along with the input parameters and return value */

int meaningfulName(int param) 
{
    int value;
    
    value += param;

    //Avoid using multiple return statements
    return value + param;

}