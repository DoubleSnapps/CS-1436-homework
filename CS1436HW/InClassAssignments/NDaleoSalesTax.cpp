/*  This program computes the total tax on a pre-defined purchase price,
    considering a seperate state and county sales tax. This value is
    then saved in a variable. This program has no outputs or inputs. */

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    //State and County sales tax rates are stored as constants
    const double STATE_SALES_TAX = 0.04;
    const double COUNTY_SALES_TAX = 0.02;

    double purchase = 95;

    //Sales tax are calculated with the purchase price and respective tax rate
    double stateSalesTax = purchase * STATE_SALES_TAX;
    double countySalesTax = purchase * COUNTY_SALES_TAX;

    //Total tax rate is sum of the state and county tax on purchase
    double totalSalesTax = stateSalesTax + countySalesTax;

}
