#include "account.h"
#include <vector>

// function prototypes
int findAccount(vector<Account>&, int);
void processAccount(vector<Account>&, int);
void checkPIN(vector<Account>&, int, int);

int main()
{
    //Account obj("Dharak Koradia", 3423, 1111, 100);
    vector<Account> accounts;
    int choice, userPIN;

    accounts.push_back(Account("John Doe", 3421, 1010, 55));
    accounts.push_back(Account("Will Smith", 2456, 1011, 55000));
    accounts.push_back(Account("John Travolta", 4578, 1012, 43000));
    accounts.push_back(Account("James Bond", 7777, 1013, 100000));
    accounts.push_back(Account("DK", 1221, 1014, 23));
    
   cout << "=======================";
   cout << "\nWelcome to the bank!\n";
   cout << "=======================\n\n";

   cout << "Enter the account number or 0 to quit: ";
   cin >> choice;
   while (choice != 0)
   {
       int res = findAccount(accounts, choice);
       if (res == -1)
       {
           cout << "\n---------------------------------------------------------------";
           cout << "\nSorry, no account exists with the account number: " << choice; 
           cout << "\n---------------------------------------------------------------\n";
       }
       else
       {
           cout << "\nEnter the PIN for the account: ";
           cin >> userPIN;
           checkPIN(accounts, res, userPIN);
       }

       cout << "Enter the account number or 0 to quit: ";
       cin >> choice;
       
   }

    cout << "\n\n\n_________________";
    cout << "\nHAVE A NICE DAY!\n";
    cout << "_________________\n";

    return 0;
}


// function definitions
int findAccount(vector<Account>& accountsVect, int acctNum)
{
    for (int i = 0; i < accountsVect.size(); i++)
    {
        if (accountsVect.at(i).getAcctNum() == acctNum)
        {
            return i;
        }
    }

    return -1;
}


void processAccount(vector<Account>& vect, int position)
{
    // char choice = 'y';
    int choice = 0;
    cout << "\n\nHello " << vect.at(position).getName() << ", your account is in process.\n";

    cout << "\nWhat would you like to do?"
        <<  "\n1 - Withdraw"
        << "\n2 - Deposit"
        << "\n3 - Quit"
        << "\nChoice: ";
    cin >> choice;

    cout << "\nHere are the account details: ";
    vect.at(position).printAccount();
    cout << "\n";
    double withdrawAmt, depositAmt = 0;

    while (choice >= 1 && choice <= 2)
    {

        switch (choice)
        {
        case 1:
            cout << "\nPlease enter the amount of withdrawal: $";
            cin >> withdrawAmt;
            
            if (withdrawAmt < 0)
            {
                cout << "\n-----------------------------------------------";
                cout << "\nNegative values do not work for withdrawal.";
                cout << "\n-----------------------------------------------\n";
            }
            else
            {
                cout << "\nTotal balance before the withdrawal: $" << vect.at(position).getBalance();
                vect.at(position).withdraw(withdrawAmt);
                cout << "\nTotal balance after the withdrawal: $" << vect.at(position).getBalance();
            }
            break;

        case 2:
            cout << "\nPlease enter the amount of deposit: $";
            cin >> depositAmt;
            
            if (depositAmt < 0)
            {
                cout << "\n-----------------------------------------------";
                cout << "\nNegative values do not work for deposit.";
                cout << "\n-----------------------------------------------\n";
            }
            else
            {
                cout << "\nTotal balance before the deposit: $" << vect.at(position).getBalance();
                vect.at(position).deposit(depositAmt);
                cout << "\nTotal balance after the deposit: $" << vect.at(position).getBalance();
            }
            break;

        default:
            break;
        }

        if (choice == 3)
            break;

        cout << "\n\nWhat would you like to do?"
        <<  "\n1 - Withdraw"
        << "\n2 - Deposit"
        << "\n3 - Quit"
        << "\nChoice: ";
        cin >> choice;

    }

    cout << "\n\nSummary: ";
    vect.at(position).printAccount();
    cout << "Goodbye " << vect.at(position).getName() << "!";
    cout << "\n______________________________________\n\n";
}


void checkPIN(vector<Account>& vect, int position, int userPIN)
{
    int i = 3;
    while (i >= 1)
    {
        if (vect.at(position).checkPIN(userPIN))
        {
            processAccount(vect, position);
            break;
        }
        else
        {
            i--;
            if (i == 0)
            {
                cout << "\nSecurity error!!!\n\n\n";
                break;
            }
            else
            {
                cout << "\nInvalid PIN, " << i << " attempt(s) left.\n"
                << "Please re-enter PIN: ";
                cin >> userPIN;
            }
              
        }

    }
    
}
