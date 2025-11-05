#include <iostream>
#include <string>

using namespace std;

int getValidPopulation(int&, int&, int&, int&, int&, int&);
void printPopulation(int, int);

int main()
{

    int pop1900, pop1920, pop1940, pop1960, pop1980, pop2000;

    cout << "Enter Prairieville's population for each year." << endl;
    cout << "Population must be greater than 1000 people" << endl;
    getValidPopulation(pop1900, pop1920, pop1940, pop1960, pop1980, pop2000);
    cout << pop1900 << pop1920 <<  pop1940 <<  pop1960 <<  pop1980 << pop2000;
}

int getValidPopulation(int &pop1900, int &pop1920, int &pop1940,
    int &pop1960, int &pop1980, int &pop2000)
{
    int population, i = 0, baseYear = 1900, currentYear;
    bool validPopulation = true;

    while (i < 6)
    {

        currentYear = baseYear + (i * 20);

        cout << "Enter " << currentYear << "'s population";

        do
        {
            cout << (validPopulation ? "" : "Invalid population, enter again;\n");
            cout << "Enter " << currentYear << "'s population";
            cin >> population;

            validPopulation = (population > 1000);
        } while (!validPopulation);

        pop1900 = (i == 0) ? population : pop1900;
        pop1920 = (i == 1) ? population : pop1920;
        pop1940 = (i == 2) ? population : pop1940;
        pop1960 = (i == 3) ? population : pop1960;
        pop1980 = (i == 4) ? population : pop1980;
        pop2000 = (i == 5) ? population : pop2000;

        i++;
    }

    return population % 1000;
}

void printPopulation(int year, int population)
{
    int i;

    cout << year << " ";

    for (i = 0; i < population; i++)
    {
        cout << "*";
    }
}