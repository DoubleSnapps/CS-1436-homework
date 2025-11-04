/*  This program allows the user to engage
    in a match of rock, paper, and scissors
    with the computer. An input of move
    choice (R/r, P/p, or S/s) is taken.
    The result of the match is output,
    and if it results in a tie,
    the another match will start. */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int generateRPSChoice();
int getRPSChoice();
bool validatePlayerMove(char);
int convertCharMove(char);
string battleRPS(int, int, bool&);

int main()
{
    string result = "tie";
    int playerMove, computerMove;
    bool playerWin = false, tied = false;

    do
    {
        computerMove = generateRPSChoice();

        playerMove = getRPSChoice();

        result = battleRPS(playerMove, computerMove, playerWin);

        tied = (result == "tie");

        cout << (!tied ? (result + "\n") : "");

        // If not tied, print win or loss, if tied, play again
        cout << ((!tied) ? (playerWin ? "You Win!" : "The Computer Wins!") : "You are tied, Play again!"); 
    }
    while (1);

}

/*  This function generates 
    rock, paper, or scissors.
    Returns: 1 (rock), 2 (paper), 
        or 3 (scissors) (int)   */
int generateRPSChoice()
{
    int computerMove;

    srand(time(0));

    computerMove = (rand() % 3) + 1;
    cout << "Com move" << computerMove << endl;

    return computerMove;
}

/*  This function gets a user choice 
    of rock, paper, or scissors.
    Returns: 1 (rock), 2 (paper), 
        or 3 (scissors) (int)   */
int getRPSChoice()
{
    char playerMove;
    int playerMoveNum;
    bool selectedMove = false;

    // runs while selected move is invalid
    while (!selectedMove)
    {
        cout << "Choose corresponding character for Rock, Paper, or Scissors." << endl;
        cout << "\tRock: r" << endl;
        cout << "\tPaper: p" << endl;
        cout << "\tScissors: s" << endl;
        cin >> playerMove;

        selectedMove = validatePlayerMove(playerMove);
    }

    playerMoveNum = convertCharMove(playerMove);

    return playerMoveNum;
}

/*  This function checks if the 
    entered character is an acceptable move. 
    Requires: player's move (char)
    Returns: if it is valid (bool)  */
bool validatePlayerMove(char playerMove)
{
    bool valid = false;

    switch (playerMove)
    {
    case 'R':
    case 'r':
    case 'P':
    case 'p':
    case 'S':
    case 's':
        valid = true;
        break;
    }

    return valid;
}

/*  This function converts a  
    entered RPS move to an int form 
    Requires: player's move (char)
    Returns: 1 (R/r), 2 (P/p), 
        or 3 (S/s) (int)  */
int convertCharMove(char playerMove)
{
    int move = 0;

    switch (playerMove)
    {
    case 'R':
    case 'r':
        move = 1;
        break;
    case 'P':
    case 'p':
        move = 2;
        break;
    case 'S':
    case 's':
        move = 3;
        break;
    }

    return move;
}

/*  This function determines the outcome of a RPS match.
    Requires: player one's choice (int)
    Requires: player two's choice (int)
    Requires: player win variable (bool, pass by reference)
    Returns: string of match outcome (string), playerWin pass by ref (bool) */
string battleRPS(int p1Choice, int p2choice, bool &playerWin)
{

    string result = "";
    playerWin = false;

    if (p1Choice == p2choice)
    {
        result = "tie";
    }
    else if (p1Choice == 1 && p2choice == 2)
    {
        result = "Paper wraps rock!";
        playerWin = false;
    }
    else if (p1Choice == 1 && p2choice == 3)
    {
        result = "Rock smashes scissors!";
        playerWin = true;
    }
    else if (p1Choice == 2 && p2choice == 1)
    {
        result = "Paper wraps rock!";
        playerWin = true;
    }
    else if (p1Choice == 2 && p2choice == 3)
    {
        result = "Scissors cuts paper!";
        playerWin = false;
    }
    else if (p1Choice == 3 && p2choice == 1)
    {
        result = "Rock smashes scissors!";
        playerWin = false;
    }
    else if (p1Choice == 3 && p2choice == 2)
    {
        result = "Scissors cuts paper!";
        playerWin = true;
    }

    return result;
}