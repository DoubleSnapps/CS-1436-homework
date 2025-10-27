/*  Using the quadratic formula, this program calculates the root of a quadratic function.
    No inputs or outputs are needed/given, the program utilizes predefiend values.  */

#include<iostream>
#include<cmath>

using namespace std;

int main()
{

    double a = 1, b = -5, c = 6;

    /*  posResult and negResult are not necessarily positive or negative,
        they just define if the square root of terms is being added or subtracted.   */
    double posResult, negResult;

    /*  Negative B is added/subtracted with the square root of b^2 minus 4 times a and c, 
        and then divided by 2 times a   */
        
    posResult = (-b + sqrt(pow(b,2) - (4 * a * c))) / (2 * a);

    negResult = (-b - sqrt(pow(b,2) - (4 * a * c))) / (2 * a);

    return 0;

}