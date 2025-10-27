/*  This program simulates a game of craps using randomly generated numbers.
    It can take an input of a seed if the useTime as seed bool is set to false. 
    it outputs the dice rolls and the resulting outcome.    */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    bool useTime = false;
    unsigned int seed;

    int dice1, dice2, diceTotal;

    string playerWin = "Player wins.", keepRolling = "Keep rolling.",
        playerLose = "Player loses.", startOver = "Start Over.", result;

    if (useTime)
    {
        srand(time(0));
    }
    else
    {
        cin >> seed;
        srand(seed);
    }

    // [1,6]
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;

    diceTotal = dice1 + dice2;

    cout << "Die 1: " << dice1 << endl;
    cout << "Die 2: " << dice2 << endl << endl;

    // If dice is less than 3, player win
    if (diceTotal <= 3)
    {
        result = playerWin;
    }

    // if dice is 4,5,6,8,9,10, keep rolling
    if ((diceTotal >= 4 && diceTotal <= 6) || (diceTotal >= 8 && diceTotal <= 10))
    {
        result = keepRolling;
    }

    // if dice is 7 or 11, player looses
    if (diceTotal == 7 || diceTotal == 11)
    {
        result = playerLose;
    }

    // if dice is 12, start over
    if (diceTotal == 12)
    {
        result = startOver;
    }

    // a result value stores the result for streamlined programming
    cout << result;

    return 0;
}