#include <iostream>
using namespace std;

#include "Monster.h"

Monster::Monster(string name, int ac, int hp, int lev)
{
    MonsterName = name;
    AC = ac;
    MonsterHP = hp;
    Level = lev;
}

void Monster::PrintMonster()
{
    cout << "Monster Name: " << MonsterName << endl;
    cout << "AC: " << AC << endl;
    cout << "HP: " << MonsterHP << endl;
    cout << "Level: " << Level << endl;
}

int Monster::RandNumGen()
{
    int RandomNumber;
    // lower + rand() % (upper - lower + 1)
    RandomNumber = 0 + rand() % (2 - 0 + 1);
    return RandomNumber;
}

