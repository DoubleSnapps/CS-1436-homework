/*  This program utilizes a menu-based loop to determine
    the occupancy of a hotel. Inputs of menu choices are 
    taken from the user, as well as room numbers and their
    occupancy status if the user chooses a floor from the menu.
    The program outputs the selected menu options, as well as
    the occupancy report if chosen. */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void menuManager();
void printPrompt(bool = false);
char getAction();
void reportOccupancy(int, int);
void getRoomStatus(int, int &, int &);
bool validateAction(char);
bool validateRoomStatus(char);

int main()
{

    menuManager();

    cout << "Exiting Program.";

    return 0;
}

/*  This function preforms the primary looping
    menu operations for the hotel simulation.
    Requires: occupied rooms (int)
    Requires: vacant rooms (int)
    Returns: occupied and vacant rooms as pass by refs. (int, int)  */
void menuManager()
{
    int occupied = 0, vacant = 0, floorNumber;
    char action;
    bool validAction = true, contLoop = true;

    // primary do-while loop that executes until user enters x to end
    do
    {

        action = getAction();

        // once action is chosen, if statements preform the corresponding action

        if (action == 'r' || action == 'R')
        {
            cout << "hello";
            reportOccupancy(occupied, vacant);
        }
        else if (action == 'x' || action == 'X')
        {
            contLoop = false;
        }
        else
        {
            /* At this point, action is either '1', '2' or '3',
                so we just subtract the ASCII code by 48 to get 1, 2, or 3    */
            floorNumber = action - 48;

            getRoomStatus(floorNumber, occupied, vacant);
        }
    } while (contLoop);
}

/*  This function gets a menu action from the
    user, input validation loop is present.
    Returns: menu action (char)   */
char getAction()
{
    char action;
    bool validAction = true;

    // this loop gets a menu action; runs until a valid action is chosen
    do
    {
        printPrompt(!validAction);
        cin >> action;

        validAction = validateAction(action);

    } while (!validAction);

    return action;
}

/*  This function prints the menu prompt.
    Requires: if to print error message (bool, default value of false)  */
void printPrompt(bool errMsg)
{
    cout << (errMsg ? "Invalid Menu Action; please try again\n" : "");
    cout << "Enter Floor Number or action: " << endl;
    cout << "\t1st Floor - 1\n";
    cout << "\t2nd Floor - 2\n";
    cout << "\t3rd Floor - 3\n";
    cout << "\tView Occupancy Report - r\n";
    cout << "\tExit Program - x\n";
}

/*  This function prints the
    occupancy report for the hotel.
    Requires: # of occupied rooms (int)
    Requires: # of vacant rooms (int)   */
void reportOccupancy(int occupied, int vacant)
{
    char ch;
    double occupancyPercentage, rooms;

    cout << endl << "debugging vacant" << vacant << " occupied" << occupied; 

    rooms = occupied + vacant;

    cout << endl << "debugging rooms" << rooms;
    cout << endl << "debugging vacant" << vacant << " occupied" << occupied; 

    occupancyPercentage = (occupied / rooms) * 100;

    cout << endl << endl << fixed << setprecision(2);
    cout << "Occupancy Report of " << rooms << " rooms -" << endl;
    cout << "\t" << occupied << " Occupied Rooms" << endl;
    cout << "\t" << vacant << " Vacant Rooms" << endl;
    cout << "\t" << occupancyPercentage << "% Occupancy Rate" << endl;
    cout << endl;

    // A useless cin is used to let the user "pause" and look at the report
    cout << "Enter any character to continue." << endl;
    cin >> ch;
    cout << endl;

}

/*  This function gets the the occupancy 
    status of hotel rooms within the same floor. 
    Requires: Floor Number (int)
    Requires: occupied rooms (pass by reference)
    Requires: vacant rooms (pass by reference)
    Returns: occupied and vacant rooms as pass by refs. (int, int)  */
void getRoomStatus(int floorNumber, int &occupied, int &vacant)
{
    int roomNumber = 0;
    char roomStatus;
    bool validStatus = true;

    while (roomNumber != -1)
    {
        /* room status is reset each loop so that a 'leftover'
            value isn't added to occupied or vacant when the user enters -1   */
        roomStatus = 'n';

        cout << "Enter Floor #" << floorNumber << " Room Number: " << endl;
        cout << "\tEnter -1 to return to menu" << endl;
        cin >> roomNumber;

        if (roomNumber != -1)
        {
            do
            {
                cout << (!validStatus ? "Invalid Room status entered; try again\n" : "");
                cout << "Is Room #" << roomNumber << " Occupied?" << endl;
                cout << "\t Occupied - O" << endl;
                cout << "\t Vacant - V" << endl;
                cin >> roomStatus;

                validStatus = validateRoomStatus(roomStatus);
            } 
            while (!validStatus);
        }

        // if the room status is occupied or vacant, it is added to the total
        occupied += (roomStatus == 'O' || roomStatus == 'o');
        vacant += (roomStatus == 'V' || roomStatus == 'v');

    }

}

/*  This function checks the validity of a menu action.
    Requires: menu action (char)
    Returns: validity (bool)    */
bool validateAction(char action)
{
    bool validAction = false;

    switch (action)
    {
    case '1':
    case '2':
    case '3':
    case 'R':
    case 'r':
    case 'X':
    case 'x':
        validAction = true;
        break;
    }

    return validAction;
}

/*  This function checks the validity of a room's status
    Requires: room status (char)
    Returns: validity (bool)    */
bool validateRoomStatus(char roomStatus)
{
    bool validStatus = false;

    switch (roomStatus)
    {
    case 'O':
    case 'o':
    case 'V':
    case 'v':
        validStatus = true;
        break;
    }

    return validStatus;
}