#include "Character.h"
class Novice : public Character
{
private:
    int Luck;

public:
    Novice(string);
    int getAttack();
    void updateXP(int);
    void updateHP(int);
    void heal();
    void print();
    void Fight(Monster &);
};