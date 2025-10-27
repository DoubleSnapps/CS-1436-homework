#include <iostream>

using namespace std;

bool voteEligibility(int);

int main()
{

    int age;
    bool eligibility, validAge = false;

    //----------------User Prompt----------------

    cout << "Enter your age: ";
    cin >> age;
    cout << endl;

    //----------------Input Validation----------------

    validAge = (age >= 0);

    //----------------Result Output----------------

    eligibility = voteEligibility(age);

    if (validAge)
    {
        if (eligibility)
        {
            cout << "You are eligible to vote.";
        }
        else
        {
            cout << "You are not eligible to vote.";
        }
    }
    else
    {
        cout << "Please enter valid age.";
    }
}

bool voteEligibility(int age)
{
    return (age >= 18);
}