#include "account.h"

Account::Account()
{
    balance = 0;
    name = "NO NAME";
    accountNum = PIN = 0;
}

Account::Account(string userName, int userAcctNum, int pin, double userBalance)
{
    name = userName;
    accountNum = userAcctNum;
    PIN = pin;
    balance = userBalance;
}

void Account::printAccount()
{
    cout << "\n===============================";
    cout << "\nName: " << name;
    cout << "\nAccount number: " << accountNum;
    cout << "\nBalance: $" << fixed << setprecision(2) << balance; 
    cout << "\n===============================\n";

}

void Account::setName(string userName)
{
    while (userName.empty())
    {
        cout << "\nName cannot be an empty space, please re-enter: ";
        cin >> userName;
    }
    name = userName;
}

void Account::setAcctNum(int userAcctNum)
{
    accountNum = userAcctNum;
}

string Account::getName()
{
    return name;
}

int Account::getAcctNum()
{
    return accountNum;
}

double Account::getBalance()
{
    return balance;
}

void Account::setPIN(int pin)
{
    PIN = pin;
}

bool Account::checkPIN(int pin)
{
    if (PIN == pin)
        return true;
    else
        return false;
}

void Account::deposit(double addBalance)
{
    if (addBalance > 0)
        balance += addBalance;
}

void Account::withdraw(double withdrawAmt)
{   
    if (withdrawAmt > 0)
    {
        if (withdrawAmt > balance)
        {
            cout << "\n-----------------------------------------";
            cout << "\nCannot withdraw more than the balance!";
            cout << "\n-----------------------------------------";
            
        }
        else
        {
            balance -= withdrawAmt;
        }   
    }
}

