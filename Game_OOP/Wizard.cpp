#include "Wizard.h"
#include <iostream>

Wizard::Wizard(string name, int magic)
{
    Name = name;
    HP = 100;
    XP = 0;
    PointsToNextLevel = 10;
    Divine = magic;
    MaxHP = HP;
}

int Wizard::getAttack()
{
    int AttkPts;
    // lower + rand() % (upper - lower + 1) + Divine (i.e., 5)

    AttkPts = (5 + rand() % (15 - 5 + 1)) + 5;
    return AttkPts;
}


void Wizard::updateXP(int MonstersLevelPts)
{
    XP = XP + (MonstersLevelPts - 2);

    // when XP reaches to a certain amount, then...

    if (XP >= PointsToNextLevel)
    {
        // "level up" and gain some increase in all stats
        cout << endl
             << "LEVEL UP!" << endl;
        HP += 8;
        Divine += 3; // Magic increases by 3.

        PointsToNextLevel += 14;
    }
}

void Wizard::updateHP(int damage)
{
    // You lose. You lose Health Points(HP) - magic enemy damage (Divine)
    HP = HP - (damage - Divine);

    if (HP < 0)
    {
        heal();
        cout << "HP were 'healed' " << endl;
    }
}

void Wizard::heal()
{
    // restores the HP to MaxHP value (i.e., HP = 100)
    HP = MaxHP;
}

void Wizard::print()
{
    cout << "Wizard type character:" << endl;
    cout << "Name is " << Name << endl;
    cout << "Health Points: " << HP << endl;
    cout << "Experience (XP): " << XP << endl;
    cout << "Points to next level: " << PointsToNextLevel << endl;
    cout << "Heal HP: " << MaxHP << endl;

    cout << endl;
    cout << "Divine: " << Divine << endl;
}

// ------------------- 
// **** FIGHT! **** // 
// ------------------

void Wizard::Fight(Monster &MonstObj)
{
    // get attack numbers for Novice from randon number generator
    AttackPoints = getAttack();
    cout << endl << "Attack Points: " << AttackPoints << endl;
    cout << "Monster's AC: " << MonstObj.getMonstAC() << endl;
    cout << "_______________________________________" << endl
         << "RESULT:" << endl
         << "_______________________________________" << endl;

    if (AttackPoints > MonstObj.getMonstAC())
    {
        // YOU WIN !
        cout << endl << "YOU WON!" << endl;

        // updateXP based on the monster's level points
        updateXP(MonstObj.getMonstLevPts());

        // Print the updated characteristics
        cout << "----------------------" << endl;
        print();
        cout << "----------------------" << endl;
    }
    else
    {
        // You Lose
        cout << endl << "You lost." << endl;

        // updateHP based on monster's AC
        updateHP(MonstObj.getMonstAC());
        
        // Print the updated characteristics
        cout << "----------------------" << endl;
        print();
        cout << "----------------------" << endl;
    }
    cout << "_______________________________________" << endl;
}
