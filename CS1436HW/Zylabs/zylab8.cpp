#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double stockSale, commission;

    cout << "Please enter the amount of the stock sale: $ ";
    cin >> stockSale;
    cout << endl << fixed << setprecision(2);

    if (stockSale > 0)
    {

        if (stockSale > 100000)
        {
            commission = 1000;
        }
        else if (stockSale > 10000 && stockSale <= 100000)
        {
            commission = (130 + (0.0075 * (stockSale - 10000.0)));
        }
        else if (stockSale > 1500 && stockSale <= 10000)
        {
            commission = 45 + (0.01 * (stockSale - 1000.0));
        }
        else if (stockSale > 500 && stockSale <= 1500)
        {
            commission = 35 + (0.02 * (stockSale - 500.0));
        }

        else if (stockSale <= 500)
        {
            commission = 35.0;
        }

        cout << "The commission is $" << commission << endl;
    }
    else
    {
        cout << "Error, invalid sales amount entered." << endl;
    }

    return 0;

}