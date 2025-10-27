/*  This program calculates what percentage of calories
    come from fat in a food item. It takes an input of
    the total calories and grams of fat from the user.
    It outputs the percentage of calories the fat makes
    up, and will identify if a food is low in fat.
    It utilizes input validation to make sure the grams
    of fat and calories are positive, and that fat calories
    is not greater than the total calories.   */

#include<iostream>
#include<iomanip>

using namespace std;

double const FAT_GRAM_CAL = 9.0;

double caloriesOfFat(double);

int main() 
{

    double calories, fatGrams, fatCalories, fatCaloriesPercentage;
    bool isLowfat, validCalAndFatCount, validFatCalContent;

    isLowfat = validCalAndFatCount = validFatCalContent = false;

    //----------------User Prompt----------------

    cout << "Enter the amount of calories in the food: " << endl;
    cin >> calories;
    cout << endl;

    cout << "Enter the grams of fat in the food: " << endl;
    cin >> fatGrams;
    cout << endl << fixed << setprecision(2);

    //----------------Input Validation----------------

    validCalAndFatCount = ((fatGrams > 0) && (calories > 0)); 

    fatCalories = caloriesOfFat(fatGrams);

    validFatCalContent = (calories > fatCalories);

    // if statement is used to prevent division by 0
    if(validCalAndFatCount)
    {
        fatCaloriesPercentage = (fatCalories/calories * 100);
        isLowfat = (fatCaloriesPercentage <= 30);
    }

    //----------------Result Output----------------

    if(validCalAndFatCount && validFatCalContent)
    {
        cout << "Of the " << calories << " calories, " 
            << fatCaloriesPercentage << "% come from fat." << endl;

        cout << (isLowfat ? "This food is low in fat." : ""); 
    }
    else
    {
        cout << "Either calories or grams of fat were entered incorrectly." << endl;
        cout << "Ending the program; Please Try again";
    }

    return 0;

}

/*  This function calculates the amount of calories
    in a food that come from its fat content.
    Requires: grams of fat in food (double)
    Returns: amount of calories in fat (double)    */
double caloriesOfFat(double fatGrams)
{
    return (fatGrams * FAT_GRAM_CAL);
}


