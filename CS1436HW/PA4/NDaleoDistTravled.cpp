#include <iostream>

using namespace std;

int main()
{

    double speed, distance;
    int i = 1, time;

    cout << "Enter speed of vehicle: " << endl;
    cin >> speed;
    cout << "Enter hours traveled: " << endl;
    cin >> time;
    if (speed >= 0 && !(time < 1))
    {
        cout << "Hour-distance traveled" << endl;
        cout << "------------------" << endl;
        while (i <= time)
        {
            cout << i << "\t" << (speed * i);
            cout << endl;
            i++;
        }
    }
    else
    {
        cout << "Invalid values entered" << endl;
    }

    return 0;
}