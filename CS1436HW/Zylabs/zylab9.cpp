/*  This program calculates the amount of time it takes for 
    sound to travel trough a given distance in a specific 
    material. It takes a menu input of material type from the user
    (wood, steel, water or air) and the given distance for
    sound to travel. It then outputs the amount of time
    that is needed for sound to travel that distance through
    the specified material. */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    const double WOOD_SPEED = 12631.230, STEEL_SPEED = 10614.815,
                 WATER_SPEED = 4714.572, AIR_SPEED = 1125.334;

    unsigned int mediumChoice;
    double distTraveled, travelTime;
    string mediumChoiceStr;
    bool validMedium = false, validDistance = false;

    // User Prompt

    cout << "\t" << "Time for Sound to Travel through a Medium given Distance" << endl
         << endl;
    cout << "1 - Wood" << endl;
    cout << "2 - Steel" << endl;
    cout << "3 - Water" << endl;
    cout << "4 - Air" << endl
         << endl;

    cout << "Enter the number of the medium: ";
    cin >> mediumChoice;

    cout << "Enter the distance to travel (in feet): ";
    cin >> distTraveled;

    // Input Validation

    // If choice is 1,2,3, or 4, then it is valid
    switch (mediumChoice)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            validMedium = true;
            break;

        default:
            cout << endl
                    << "Error, invalid medium!" << endl
                    << "Please run the program again." << endl;
            validMedium = false;
            break;
    }

    // if distance is less than 0, it is invalid
    if (distTraveled <= 0)
    {
        cout << endl
             << "Input error! The distance must be greater than zero.";
        validDistance = false;
    } 
    else 
    {
        validDistance = true;
    }

    // Result Output

    if (validMedium && validDistance)
    {
        // Distance divided by respective speed constants
        switch (mediumChoice)
        {
            case 1:
                travelTime = distTraveled / WOOD_SPEED;
                mediumChoiceStr = "wood";
                break;
            case 2:
                travelTime = distTraveled / STEEL_SPEED;
                mediumChoiceStr = "steel";
                break;
            case 3:
                travelTime = distTraveled / WATER_SPEED;
                mediumChoiceStr = "water";
                break;
            case 4:
                travelTime = distTraveled / AIR_SPEED;
                mediumChoiceStr = "air";
                break;
        }

        cout << endl << fixed << setprecision(4) << "In " << mediumChoiceStr 
            << " it will take " << travelTime << setprecision(1) 
            << " seconds to travel " << distTraveled << " feet." << endl;
    }
    
    return 0;
    
}