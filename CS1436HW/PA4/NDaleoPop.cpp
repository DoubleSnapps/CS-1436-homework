#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getValidPopulation(int&, int&, int&, int&, int&, int&);
void printPopulationAsterisk(int, int);
void populationReport(int, int, int, int, int, int);

int main()
{

    int pop1900, pop1920, pop1940, pop1960, pop1980, pop2000;

    getValidPopulation(pop1900, pop1920, pop1940, pop1960, pop1980, pop2000);

    populationReport(pop1900, pop1920, pop1940, pop1960, pop1980, pop2000);
    
    return 0;

}

int getValidPopulation(int &pop1900, int &pop1920, int &pop1940,
    int &pop1960, int &pop1980, int &pop2000)
{
    int population, i = 0, baseYear = 1900, currentYear;
    bool validPopulation = true;

    cout << "Enter Prairieville's population for each year." << endl;
    cout << "(Population must be greater than 1000 people)" << endl;

    while (i < 6)
    {

        currentYear = baseYear + (i * 20);

        do
        {
            cout << (validPopulation ? "" : "Invalid population, enter again;\n");
            cout << "Enter " << currentYear << "'s population ";
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

void printPopulationAsterisk(string year, int population)
{
    int i;

    cout << year;

    population = round(population / 1000.0);

    for (i = 0; i < population; i++)
    {
        cout << "*";
    }

    cout << endl;

}

void populationReport(int pop1900, int pop1920, int pop1940,
    int pop1960, int pop1980, int pop2000)
{
    int i = 0, currentPopulation;
    string populationYear;

    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "\t(each * represents 1,000 people)" << endl;

    while(i < 6)
    {

        // the poor mans arrays

        currentPopulation = (i == 0) ? pop1900 : currentPopulation;
        currentPopulation = (i == 1) ? pop1920 : currentPopulation;
        currentPopulation = (i == 2) ? pop1940 : currentPopulation;
        currentPopulation = (i == 3) ? pop1960 : currentPopulation;
        currentPopulation = (i == 4) ? pop1980 : currentPopulation;
        currentPopulation = (i == 5) ? pop2000 : currentPopulation;

        populationYear = (i == 0) ? "1900 " : populationYear;
        populationYear = (i == 1) ? "1920 " : populationYear;
        populationYear = (i == 2) ? "1940 " : populationYear;
        populationYear = (i == 3) ? "1960 " : populationYear;
        populationYear = (i == 4) ? "1980 " : populationYear;
        populationYear = (i == 5) ? "2000 " : populationYear;

        printPopulationAsterisk(populationYear, currentPopulation);

        i++;

    }

}