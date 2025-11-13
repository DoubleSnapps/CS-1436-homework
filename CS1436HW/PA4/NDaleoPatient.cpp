/*  This program calculates a user's hospital bill.
    It takes an input of the user's patient type
    (in-patient or out-patient), medication and
    services cost, and days spent and daily rate
    of stay if the patient answers in patient.
    It outputs the users bill for the hospital.    */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool getPatientType();
double calculateBill(double, double);
double calculateBill(int, double, double, double);
double getDoubleInput(string);

int main()
{
    int days;
    double hospitalBill, dailyRate, medication, services;
    string daysMsg = "Enter days spent in hospital (#): ", rateMsg = "Enter daily cost ($): ",
           medicationMsg = "Enter cost of medication(s) ($): ", servicesMsg = "Enter cost of services ($): ";
    bool isInPatient;

    //----------------User Prompts----------------

    isInPatient = getPatientType();

    if (isInPatient)
    {
        days = getDoubleInput(daysMsg);
        dailyRate = getDoubleInput(rateMsg);
    }

    medication = getDoubleInput(medicationMsg);
    services = getDoubleInput(servicesMsg);

    //----------------Bill Calculation----------------

    // if inpatient, call calculateBill() with 4 arguments, if not, call with 2
    hospitalBill = (isInPatient ? calculateBill(days, dailyRate, medication, services) :
        calculateBill(medication, services));

    //----------------Bill Output----------------

    cout << fixed << setprecision(2);
    cout << "Hospital Bill: $" << hospitalBill << "." << endl;

    return 0;
    
}

/*  This function asks the user
    where they are an In or Out
    patient. It loops until the
    user enters i or o (case insensitive)
    Returns: true if in patient, false if out (bool)    */
bool getPatientType()
{
    char patient;
    bool isInPatient, validAnswer = true;

    do
    {
        cout << (validAnswer ? "Invalid Option Entered; Try Again\n" : "");
        cout << "Enter Your Patient Type as character: " << endl;
        cout << "\tIn-Patient - i" << endl;
        cout << "\tOut-Patient - o" << endl;
        cin >> patient;

        // we love case insensitivity
        validAnswer = (patient == 'i' || patient == 'o' || patient == 'I' || patient == 'O');

    } 
    while (!validAnswer);

    return (patient == 'i' || patient == 'I');
}

/*  This function gets a non-negative
    double from the user. It runs
    until a valid (>=0) value is given.
    Requires: prompt for user (string)
    Returns: user entered value (double)  */
double getDoubleInput(string msg)
{

    double value = 0;
    bool validValue = true;

    do
    {
        cout << (validValue ? "" : "Invalid Value Entered; Try again\n");
        cout << msg;
        cin >> value;

        validValue = (value >= 0);

    } 
    while (!validValue);

    return value;

}

/*  This function calculates the total
    bill the user owes the hospital.
    Requires: cost of medication (double)
    Requires: cost of services (double)
    Returns: bill cost (double) */
double calculateBill(double medication, double services)
{

    double totalBill;

    /*  medication and service charges   */
    totalBill = medication + services;

    return totalBill;

}

/*  This function calculates the total
    bill the user owes the hospital.
    Requires: days spent in hospital (int)
    Requires: daily rate of stay (double)
    Requires: cost of medication (double)
    Requires: cost of services (double)
    Returns: bill cost (double) */
double calculateBill(int days, double dailyRate,
                     double medication, double services)
{

    double totalBill;

    /* daily rate paid for each day, plus
        additional medication and service charges   */
    totalBill = (days * dailyRate) + medication + services;

    return totalBill;

}
