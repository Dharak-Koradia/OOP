#include "Character.h"
class Knight : public Character
{
private:
    string WeaponName;
    int WeaponPower;
    int Armor;

public:
    Knight(string, string);
    int getAttack();
    void updateXP(int);
    void updateHP(int);
    void heal();
    void print();
    void Fight(Monster &);
};