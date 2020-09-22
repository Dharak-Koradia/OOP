#include "Character.h"
class Wizard : public Character
{
private:
    int Divine;

public:
    Wizard(string, int);
    int getAttack();
    void updateXP(int);
    void updateHP(int);
    void heal();
    void print();
    void Fight(Monster &);
};