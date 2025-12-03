/*  This program finds individual salaries owed 
    to a group of employee's, as well as the 
    average salary across them. It takes inputs 
    of each employee's hours worked in the week. 
    It outputs a chart of each employee's hours 
    worked and salary owed, as well as the average 
    salary across the employees.*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    const int WORKERS = 10, MAX_HOURS = 40, REG_PAY = 10, OVERTIME_PAY = (REG_PAY * 1.5);
    
    double employeeHours[WORKERS] = {0}, employeeSalary[WORKERS] = {0}, averageSalary = 0;
    int i;

    // get employee hours
    for(i = 0; i < WORKERS; i++)
    {
        cout << "Enter employee #" << (i + 1) << "'s hours this week: ";
        cin >> employeeHours[i];
    }

    // calculate employee salary
    for(i = 0; i < WORKERS; i++)
    {
        // if employee has worked less than max, no overtime is owed
        if(employeeHours[i] <= MAX_HOURS)
        {
            employeeSalary[i] = employeeHours[i] * REG_PAY;
        }
        else
        {
            // salary is max hours * regular pay rate plus overtime hours * overtime pay
            employeeSalary[i] = (MAX_HOURS * REG_PAY) + ((employeeHours[i] - MAX_HOURS) * OVERTIME_PAY);
        }

    }

    // print each employee's hours and salary
    cout << "EMPLOYEE #\tHOURS\tSALARY" << endl;

    for(i = 0; i < WORKERS; i++)
    {
        cout << (i + 1) << "\t" << employeeHours[i] << "\t" << employeeSalary[i];
        cout << endl;
    }

    // calculate average salary, adds all salary then divides by # of workers

    for(i = 0; i < WORKERS; i++)
    {
        averageSalary += employeeSalary[i];
    }

    averageSalary /= WORKERS;

    // print average salary

    cout << "Average pay is: $" << averageSalary << endl; 


    return 0;

}

