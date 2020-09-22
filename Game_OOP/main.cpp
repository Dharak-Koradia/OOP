#include <stdlib.h> 
#include <iostream> 
#include <vector> 
#include <ctime> 
using namespace std;

#include "Character.h" 
#include "Knight.h" 
#include "Novice.h" 
#include "Wizard.h" 
#include "Monster.h"

// Function Prototypes
int FuncMenu();
void CreateCharacter(vector<Character *> &);
void PrintCharacters(vector<Character *> &);
void SelectCharacter(vector<Character *> &);

int main()
{
    srand((time(0)));

    vector<Character *> baseptr;

    int MainMenu = FuncMenu();

    while (MainMenu != 4)
    {
        if (MainMenu == 1)
        {
            CreateCharacter(baseptr);
        }
        else if (MainMenu == 2)
        {
            PrintCharacters(baseptr);
        }
        else if (MainMenu == 3)
        {
            cout << endl << endl;

            if (baseptr.size() == 0)
            {
                cout << "No Characters!!" << endl
                     << "Create a character and then select." << endl;
            }
            else
                SelectCharacter(baseptr);
        }

        MainMenu = FuncMenu();
    }

    return 0;
}

// **********************************************************
//                     FUNCTION DEFINITIONS
// **********************************************************

int FuncMenu()
{
    int choice;

    cout << endl;
    cout << "1 - Create a character" << endl;
    cout << "2 - Print all character stats" << endl;
    cout << "3 - Select a character" << endl;
    cout << "4 - Quit" << endl;
    cout << "Enter a choice: ";
    cin >> choice;

    return choice;
}

void CreateCharacter(vector<Character *> &baseptr_1)
{
    // baseptr is the vector of POINTERS of Character data type -- i.e., it is a base-class pointer
    // and it can hold the inherited class's objects (Polymorphism)
    int charChoice, magic;

    string charName, weaponName;
    cout << "1 - Novice" << endl;
    cout << "2 - Knight" << endl;
    cout << "3 - Wizard" << endl;
    cout << "Type of character, Enter a choice: ";
    cin >> charChoice;

    if (charChoice == 1)
    {
        cout << "Enter Name for Novice char: ";
        cin.ignore();
        getline(cin, charName);
        baseptr_1.push_back(new Novice(charName));
        cout << "Novice type character made!" << endl;
    }
    else if (charChoice == 2)
    {
        cout << "Enter Name for Knight char: ";
        cin.ignore();
        getline(cin, charName);
        cout << "Every weapon has same power." << endl
             << "Enter a desired name for weapon: ";
        getline(cin, weaponName);
        baseptr_1.push_back(new Knight(charName, weaponName));
        cout << "Knight type character made!" << endl;
    }
    else if (charChoice == 3)
    {
        cout << "Enter Name for Wizard char: ";
        cin.ignore();
        getline(cin, charName);
        cout << "Enter Magic points: (Ex: 5): ";
        cin >> magic;
        baseptr_1.push_back(new Wizard(charName, magic));
        cout << "Wizard type character made!" << endl;
    }

}

void PrintCharacters(vector<Character *> &baseptr_1)
{
    for (int i = 0; i < baseptr_1.size(); i++)
    {
        cout << endl << "-------------------------------" << endl;
        baseptr_1[i]->print();
        cout << endl << "-------------------------------" << endl;
    }

}

void SelectCharacter(vector<Character *> &baseptr_1)
{
    // Create Monsters
    Monster MonstObj[3];
    MonstObj[0] = Monster("Troglodyte", 10, 10, 2);
    MonstObj[1] = Monster("Orc Warrior", 15, 15, 3);
    MonstObj[2] = Monster("Black Dragon", 20, 20, 4);

    // select a character
    int opt3choice_1, opt3choice_2;
    int selectCharacter;

    for (int i = 0; i < baseptr_1.size(); i++)
    {
        cout << "Character " << (i + 1) << ":" << endl;
        cout << "_______________________________" << endl;
        baseptr_1[i]->print();
        cout << "_______________________________" << endl;
    }

    int howmany = baseptr_1.size();
    cout << "Select a character from above " << howmany << " characters " << endl;
    cout << "Enter the number for that character (Ex: 1): ";
    cin >> selectCharacter;

    while (selectCharacter > howmany || selectCharacter <= 0)
    {
        cout << "Invalid selection of a character!" << endl;
        cout << "Please re-enter: ";
        cin >> selectCharacter;
    }

    // go to this input's position
    Character *selectPtr = baseptr_1[selectCharacter - 1];

    // print the object (i.e. character) at that position
    for (int j = 0; j < 1; j++)
    {
        cout << endl;
        selectPtr->print();
        cout << endl;
    }

    // once you select a character, a new menu appears:
    if (selectCharacter != 0)
    {
        cout << "1 - search for battle" << endl;
        cout << "2 - rest" << endl;
        cout << "3 - quit" << endl;
        cout << "Enter choice: ";
        cin >> opt3choice_1;

        if (opt3choice_1 == 1)
        {
            // search for battle

            // Even though we created a Monster array, we can use that array name to use 
            // RandNumGen() of Monster class (or we could've just created a new Monster object
            // and then call the RandNumGen function).

            int RandNum = MonstObj->RandNumGen();
            cout << "--------------------------------" << endl;
            cout << endl << " A Monster was selected" << endl << endl;

            cout << "Monster's characteristics:" << endl;
            MonstObj[RandNum].PrintMonster();
            cout << "--------------------------------" << endl << endl;

            // Now, create an Monster object, and assign it the value of randomly
            // selected monster (from the array)

            Monster Obj = MonstObj[RandNum];
            cout << "1 - Fight" << endl;
            cout << "2 - Flee" << endl;
            cout << "Enter choice: ";
            cin >> opt3choice_2;

            if (opt3choice_2 == 1)
            {
                //Fight with the monster!
                for (int k = 0; k < 1; k++)
                {
                    selectPtr[k].Fight(Obj);
                }
            }
            else // if(opt3choice_2 == 2) --> Flee!
            {
                cout << endl << endl << "Running away!" << endl;
            }

        }
        else if (opt3choice_1 == 2)
        {
            cout << endl << endl << "Having rest..." << endl << endl;
        }
    }
}
