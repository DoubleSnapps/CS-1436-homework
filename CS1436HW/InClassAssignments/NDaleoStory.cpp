/*  This program plays a word game with the user.
    The program takes inputs of user name, age, a city, a college,
    a profession, a type of animal, and the name of an animal.
    The program then outputs a short story in which the user's inputs 
    are utilized as nouns in the story. */

#include <iostream>
#include <string>

using namespace std;

int main()
{

    //Definition and Initialization of variables
    string userName, userAge, userCity, userCollege, userProfession, userPet, userPetName;
    userName = userAge = userCity = userCollege = userProfession = userPet = userPetName = "Undefined by user";

    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "Enter your age: ";
    getline(cin, userAge);

    cout << "Enter the name of a city: ";
    getline(cin, userCity);

    cout << "Enter the name of a college or: ";
    getline(cin, userCollege);

    cout << "Enter the name of a profession or job title: ";
    getline(cin, userProfession);

    cout << "Enter a type of animal: ";
    getline(cin, userPet);

    cout << "Enter the " << userPet << "'s name: ";
    getline(cin, userPetName);

    /*  This is a complex cout statement which is meant to print out a paragraph in a uniform form
        The endls indicate when a line break comes, however they are not uniform to sentences,
        due to varying sentence length. */
    cout << "There once was a person named " << userName << " who lived in " << userCity 
        << ". At the age of " << userAge << ", " << userName << " went to college" << endl
        << "at " << userCollege << ". " << userName << " graduated and went to work as a " 
        << userProfession << ". Then, " << userName << " adopted a(n)" << endl 
        << userPet << " named " << userPetName << ". They both lived happily ever after!";

        return 0;
        
}