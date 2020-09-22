#ifndef CHARACTER_H
#define CHARACTER_H

#include <string> 
using namespace std;

#include "Monster.h"

class Character
{
protected:
    string Name;
    int HP;
    int XP;
    int PointsToNextLevel;
    int MaxHP;
    int AttackPoints;

public:
    // PURE VIRTUAL FUNCTIONS:
    virtual int getAttack() = 0;
    virtual void updateXP(int) = 0;
    virtual void updateHP(int) = 0;
    virtual void heal() = 0;
    virtual void print() = 0;
    virtual void Fight(Monster &) = 0;
};

#endif