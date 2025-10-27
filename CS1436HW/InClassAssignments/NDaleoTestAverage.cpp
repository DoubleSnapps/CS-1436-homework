/*  This program finds the average test score across 5 tests.
    It takes an input of 5 scores from the user, and then
    outputs the average based on the entered scores */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double score1, score2, score3, score4, score5, averageScore;

    cout << "Enter the first test score: " << endl;
    cin >> score1;

    cout << "Enter the second test score: " << endl;
    cin >> score2;

    cout << "Enter the third test score: " << endl;
    cin >> score3;

    cout << "Enter the fourth test score: " << endl;
    cin >> score4;

    cout << "Enter the fifth test score: " << endl;
    cin >> score5;

    // The sum of the scores is divided by 5
    averageScore = (score1 + score2 + score3 + score4 + score5) / 5;

    cout << fixed << setprecision(1) << endl;

    cout << "The average score was: " << averageScore;

    return 0;
    
}