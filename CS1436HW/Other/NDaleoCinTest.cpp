#include <iostream>
#include <string>

using namespace std;

int main()
{

    int hour, min;
    char ch;

    cout << "Enter Time in hh:mm : ";
    cin >> hour;
    cin >> ch;
    cin >> min;
    cout << hour << " " << ch << " " << min << endl;

    cout << "Enter Time in hh:mm : ";
    cin >> hour >> ch >> min;
    cout << hour << " " << ch << " " << min << endl;

    return 0;

}
