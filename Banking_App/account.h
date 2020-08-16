#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
private:
    string name;
    int accountNum, PIN;
    double balance;

public:
    Account();
    Account(string, int, int, double);
    void setName(string);
    void setAcctNum(int);

    string getName();
    int getAcctNum();

    double getBalance();
    void setPIN(int);
    bool checkPIN(int);

    void deposit(double);
    void withdraw(double);


    void printAccount();

};

#endif
