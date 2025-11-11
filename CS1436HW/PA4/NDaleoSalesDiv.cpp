/*  This program finds the highest grossing
    region within a company divided across 4
    regions. A user input is taken for each
    regions sales figure. The region with the
    highest sales figure is found and reported. */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string NORTHWEST = "northwest",
             SOUTHWEST = "southwest",
             SOUTHEAST = "southeast",
             NORTHEAST = "northeast";

double getSales(string);
void findHighest(double, double, double, double);

int main()
{

    double nwSalesFig, swSalesFig, seSalesFig, neSalesFig;
    
    nwSalesFig = getSales(NORTHWEST);
    swSalesFig = getSales(SOUTHWEST);
    seSalesFig = getSales(SOUTHEAST);
    neSalesFig = getSales(NORTHEAST);

    findHighest(nwSalesFig, swSalesFig, seSalesFig, neSalesFig);

    return 0;
}

/*  This function gets the quarterly sales
    figure in a given division from the user.
    It runs until a valid (>0) sales figure is given.
    Requires: sales division (string)
    Returns: sales figure (double)  */
double getSales(string division)
{

    double salesFig = 0;
    bool validSalesFig = true;

    do
    {
        cout << (validSalesFig ? "" : "Invalid Sales Figure; Try again\n");
        cout << "Enter " << division << "'s quarterly sales figure: ";
        cin >> salesFig;

        validSalesFig = (salesFig >= 0);

    } while (!validSalesFig);

    return salesFig;
}

/*  This function determines the highest
    sales division, and outputs the division
    and its sales figure.
    Requires: northwest sales figure (double)
    Requires: southwest sales figure (double)
    Requires: southeast sales figure (double)
    Requires: northeast sales figure (double)   */
void findHighest(double nwSalesFig, double swSalesFig,
                 double seSalesFig, double neSalesFig)
{

    double highestSalesFig;
    string highestRegion;
    bool nwHighest, swHighest, seHighest, neHighest;

    // priority is given to NW, then SW, then SE, if figures are equal
    nwHighest = (nwSalesFig >= swSalesFig && nwSalesFig >= seSalesFig && nwSalesFig >= neSalesFig);
    swHighest = (swSalesFig > nwSalesFig && swSalesFig >= seSalesFig && swSalesFig >= neSalesFig);
    seHighest = (seSalesFig > swSalesFig && seSalesFig > nwSalesFig && seSalesFig >= neSalesFig);
    neHighest = (neSalesFig > swSalesFig && neSalesFig > seSalesFig && neSalesFig > nwSalesFig);

    cout << fixed << setprecision(2);

    // ternary operators set highest region and sales fig

    highestRegion = (nwHighest ? NORTHWEST : 
        (swHighest ? SOUTHWEST : 
            (seHighest ? SOUTHEAST : NORTHEAST)));

    highestSalesFig = (nwHighest ? nwSalesFig : 
        (swHighest ? seSalesFig : 
            (seHighest ? seSalesFig : neSalesFig)));

    cout << highestRegion << " had the highest sales figure at $" << highestSalesFig;

    cout << endl;
}