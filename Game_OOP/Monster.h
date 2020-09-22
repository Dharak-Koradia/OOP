#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;
class Monster
{
private:
    string MonsterName;
    int AC, MonsterHP, Level;

public:
    Monster() { ; }
    Monster(string, int, int, int);
    int getMonstAC() { return AC; }
    int getMonstLevPts() { return Level; }
    void PrintMonster();
    int RandNumGen();
};

#endif