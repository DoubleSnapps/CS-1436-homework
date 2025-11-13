/*  This program tracks the growth of a town's population
    from 1900 to 2000. It takes a user input of population
    from 1900-2000 6 times, each increasing the year by 20
     years (1900-1920-...-2000). It outputs the population
    of the town, using asterisk to denote each 1k people.   */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void getValidPopulation(int&, int&, int&, int&, int&, int&);
void printPopulationAsterisk(int, int);
void populationReport(int, int, int, int, int, int);

int main()
{
    
    int pop1900, pop1920, pop1940, pop1960, pop1980, pop2000;

    // get populations for each year
    getValidPopulation(pop1900, pop1920, pop1940, pop1960, pop1980, pop2000);

    //generate & output report
    populationReport(pop1900, pop1920, pop1940, pop1960, pop1980, pop2000);
    
    return 0;

}

/*  This function gets the populations of the set of years
    from the user, ensuring they are > 1000.
    Requires: population of 1900 (int, pass by reference)
    Requires: population of 1920 (int, pass by reference)
    Requires: population of 1940 (int, pass by reference)
    Requires: population of 1960 (int, pass by reference)
    Requires: population of 1980 (int, pass by reference)
    Requires: population of 2000 (int, pass by reference)
    Linked: all 6 population variables  */
void getValidPopulation(int &pop1900, int &pop1920, int &pop1940,
    int &pop1960, int &pop1980, int &pop2000)
{
    int population, i = 0, baseYear = 1900, currentYear;
    bool validPopulation = true;

    cout << "Enter Prairieville's population for each year." << endl;
    cout << "\t(Population must be greater than 1000 people)" << endl;

    while (i < 6)
    {

        // 1900 + (20 * i)
        currentYear = baseYear + (i * 20);

        //----------------User Prompt and Input----------------

        do
        {
            cout << (validPopulation ? "" : "Invalid population, enter again;\n");
            cout << "Enter " << currentYear << "'s population ";
            cin >> population;

            validPopulation = (population > 1000);
        } 
        while (!validPopulation);

        // the poor mans arrays

        // population only changes if the loop is currently asking for said year's population
        pop1900 = (i == 0) ? population : pop1900;
        pop1920 = (i == 1) ? population : pop1920;
        pop1940 = (i == 2) ? population : pop1940;
        pop1960 = (i == 3) ? population : pop1960;
        pop1980 = (i == 4) ? population : pop1980;
        pop2000 = (i == 5) ? population : pop2000;

        i++;
    }

}

/*  This population prints an 
    asterisk for each 1000 people. 
    Requires: year (int)
    Requires: year's population (int)   */
void printPopulationAsterisk(int year, int population)
{
    int i;

    cout << year << " ";

    // population is divided by 1000
    population = round(population / 1000.0);

    // print one * per population
    for (i = 0; i < population; i++)
    {
        cout << "*";
    }

    cout << endl;

}

/*  This function prints a formatted population report from 1900-2000.
    Requires: population of 1900 (int)
    Requires: population of 1920 (int)
    Requires: population of 1940 (int)
    Requires: population of 1960 (int)
    Requires: population of 1980 (int)
    Requires: population of 2000 (int)  */
void populationReport(int pop1900, int pop1920, int pop1940,
    int pop1960, int pop1980, int pop2000)
{
    int i = 0, currentPopulation, populationYear;

    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "\t(each * represents 1,000 people)" << endl;

    while(i < 6)    
    {

        // the poor mans arrays
        // if i is equal to a given index, then that is the current population and current year 

        currentPopulation = (i == 0) ? pop1900 : currentPopulation;
        currentPopulation = (i == 1) ? pop1920 : currentPopulation;
        currentPopulation = (i == 2) ? pop1940 : currentPopulation;
        currentPopulation = (i == 3) ? pop1960 : currentPopulation;
        currentPopulation = (i == 4) ? pop1980 : currentPopulation;
        currentPopulation = (i == 5) ? pop2000 : currentPopulation;

        populationYear = (i == 0) ? 1900 : populationYear;
        populationYear = (i == 1) ? 1920 : populationYear;
        populationYear = (i == 2) ? 1940 : populationYear;
        populationYear = (i == 3) ? 1960 : populationYear;
        populationYear = (i == 4) ? 1980 : populationYear;
        populationYear = (i == 5) ? 2000 : populationYear;

        //----------------Population Output----------------

        printPopulationAsterisk(populationYear, currentPopulation);

        i++;

    }

}