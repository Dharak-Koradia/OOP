
#include "Novice.h"
#include "Character.h" 

#include <iostream>
using namespace std;

Novice::Novice(string name)
{
    Name = name;
    HP = 80;
    XP = 0;
    PointsToNextLevel = 10;
    Luck = 0;
    MaxHP = HP;
}

int Novice::getAttack()
{
    int AttkPts;
    // lower + rand() % (upper - lower + 1) + Luck
    AttkPts = (1 + rand() % (10 - 1 + 1)) + Luck;
    return AttkPts;
}

void Novice::updateXP(int MonsterLevelPts)
{
    XP = XP + MonsterLevelPts;

    // when XP reaches to a certain amount (i.e. Novice's PointsToNextLevel), then...
    
    if (XP >= PointsToNextLevel)
    {
        // "level up" and gain some increase in all stats
        cout << endl << "LEVEL UP!" << endl;
        HP += 10;
        Luck += 3;
        // increment next level points by 13 amounts for each class)
        PointsToNextLevel += 13;
    }

}

void Novice::updateHP(int damage)
{
    // You lose. [ You lose Health Points (HP). ]
    HP = HP - damage;

    if (HP < 0)
    {
        heal();
        cout << "HP were 'healed' " << endl;
    }
}

void Novice::heal()
{
    // restores HP to MaxHP value i.e. HP = 80 (back again)
    HP = MaxHP;
}

void Novice::print()
{
    cout << "Novice type character:" << endl;
    cout << "Name is " << Name << endl;
    cout << "Health Points: " << HP << endl;
    cout << "Experience (XP): " << XP << endl;
    cout << "Points to next level is: " << PointsToNextLevel << endl;
    cout << "Heal HP: " << MaxHP << endl;
    cout << endl;
    cout << "Luck: " << Luck << endl;
}

// ------------------- 
// **** FIGHT! **** // 
// ------------------

void Novice::Fight(Monster &MonstObj)
{
    // get attack numbers for Novice from randon number generator
    AttackPoints = getAttack();

    cout << endl
         << "Attack Points: " << AttackPoints << endl;
    cout << "Monster's AC: " << MonstObj.getMonstAC() << endl;
    cout << "_______________________________________" << endl
         << "RESULT:" << endl
         << "_______________________________________" << endl;

    if (AttackPoints > MonstObj.getMonstAC())
    {
        // YOU WIN !
        cout << endl
             << "YOU WON!" << endl;
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
        cout << endl
             << "You lost." << endl;
        // updateHP based on monster's AC
        updateHP(MonstObj.getMonstAC());
        
        // Print the updated characteristics
        cout << "----------------------" << endl;
        print();
        cout << "----------------------" << endl;
    }
    cout << "_______________________________________" << endl;
}
