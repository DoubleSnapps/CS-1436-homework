/*  This program mixes two primary colors, and reports the resulting secondary,
    or primary color. It takes two inputs of either 'red', 'blue', or 'yellow' 
    from the user. It outputs the resulting color from the combination. The
    mixed color is determined from the product of the two color string's
    length, which is unique for each unique combination.    */

#include <iostream>
#include <string>

using namespace std;

bool validateColor(string);
string mixColors(string, string);

int main()
{

    string color1, color2, mixedColors;
    bool validColors = false;

    //----------------User Prompt----------------

    cout << "Enter different primary colors in lowercase:" << endl << endl;
    cout << "\tEnter your first color: ";
    cin >> color1;
    cout << endl;
    
    cout << "\tEnter your second color: ";
    cin >> color2;
    cout << endl;

    //----------------Input Validation----------------

    validColors = (validateColor(color1) && validateColor(color2));

    //----------------Result Output----------------

    if (validColors)
    {
        mixedColors = mixColors(color1, color2);

        cout << "Mixing " << color1 << " and " << color2 << " makes " << mixedColors << "!";
    }
    else
    {
        cout << "The colors you entered were not valid." << endl;
        cout << "Ending the program; Please Try again";
    }

    return 0;
}

/*  This functions "calculates" the color created when mixing.
    Requires: color1 and color2, must be primary colors (string)
    Returns: Mixed Color Result. (string) */
string mixColors(string color1, string color2)
{

    string mixedColor = "null";

    // No product of the three primary color's string length is the same.

    /*  colorProduct Chart
            9 - Red, red and red
            12 - Purple, red and blue
            16 - Blue, blue and blue
            18 - Orange, red and yellow
            24 - Green, blue and yellow
            36 - Yellow, yellow and yellow    */

    int colorProduct = (color1.length() * color2.length());

    switch (colorProduct)
    {
    case 9:
        mixedColor = "red, a primary color";
        break;
    case 12:
        mixedColor = "purple, a secondary color";
        break;
    case 16:
        mixedColor = "blue, a primary color";
        break;
    case 18:
        mixedColor = "orange, a secondary color";
        break;
    case 24:
        mixedColor = "green, a secondary color";
        break;
    case 36:
        mixedColor = "yellow, a primary color";
        break;
    }

    return mixedColor;

}

/*  Checks if the color is a primary color
    Requires: color to validate (string)
    Returns: if the is color validity (boolean)   */
bool validateColor(string color)
{
    // color can be "red", "blue", or "yellow"
    return (color == "red" || color == "blue" || color == "yellow");
}