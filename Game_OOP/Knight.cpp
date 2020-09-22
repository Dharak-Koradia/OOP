#include "Knight.h"
#include "Character.h" 

#include <iostream>

Knight::Knight(string name, string weapName)
{
    Name = name;
    HP = 120;
    XP = 0;
    PointsToNextLevel = 10;
    MaxHP = HP;
    WeaponName = weapName;
    WeaponPower = 10;
    Armor = 1;
}

int Knight::getAttack()
{
    int AttkPts;
    // lower + rand() % (upper - lower + 1)
    AttkPts = (10 + rand() % (20 - 10 + 1)) + WeaponPower;

    return AttkPts;
}

void Knight::updateXP(int MonstersLevelPts)
{
    XP = XP + (MonstersLevelPts - 1);

    // when XP reaches to a ceratin amount, then...
    if (XP >= PointsToNextLevel)
    {
        // "level up" and gain some increase in all stats
        cout << endl << "LEVEL UP!" << endl;
        HP += 15;
        Armor += 1;
        WeaponPower += 5;

        // increase PointsToNextLevel by 11 (or by different amounts for each class)
        PointsToNextLevel += 11;
    }
}

void Knight::updateHP(int damage)
{
    // You lose. You lose --> Health Points(HP) - Armor
    HP = HP - (damage - Armor);

    if (HP < 0)
    {
        heal();
        cout << "HP were 'healed' " << endl;
    }
}

void Knight::heal()
{
    // restores the HP to MaxHP value i.e. HP = 120 (back again)
    HP = MaxHP;
}

void Knight::print()
{
    cout << "Knight type character:" << endl;
    cout << "Name is " << Name << endl;
    cout << "Health Points: " << HP << endl;
    cout << "Experience (XP): " << XP << endl;
    cout << "Points to next level: " << PointsToNextLevel << endl;
    cout << "Heal HP: " << MaxHP << endl;
    cout << endl;
    cout << "Weapon Name: " << WeaponName << endl;
    cout << "Weapon Power: " << WeaponPower << endl;
    cout << "Armor: " << Armor << endl;
}

// ------------------- 
// **** FIGHT! **** // 
// ------------------

void Knight::Fight(Monster &MonstObj)
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
        cout << endl
             << "You lost." << endl; // updateHP based on monster's AC
        updateHP(MonstObj.getMonstAC());
        
        // Print the updated characteristics
        cout << "----------------------" << endl;
        print();
        cout << "----------------------" << endl;
    }
    cout << "_______________________________________" << endl;
}
