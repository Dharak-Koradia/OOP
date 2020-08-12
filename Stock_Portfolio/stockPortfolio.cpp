#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct StockInfo
{
    string companyName;
    int numOfShares;
    double purchasePrice, currentPrice;
    double currentValue;
};

// function prototypes
int menuOption();
void addStock(vector<StockInfo>&);
void printPortfolio(vector<StockInfo>&);

int main()
{
    cout << "\n";
    
    vector<StockInfo> vect;

    int choice = menuOption();

    while (choice != 3)
    {
        if (choice == 1)
        {
            //cout << "\nUsing Add stock option";
            addStock(vect);
        }
        else
        {
            // cout << "\noption 2 chosen";
            printPortfolio(vect);
        }

        choice = menuOption();
    }
    
    cout << "\n===========";
    cout << "\nSUMMARY\n";
    printPortfolio(vect);
    cout << "\n===========";

    cout << "\n\n\nGoodbye!\n\n";
    return 0;
}



int menuOption()
{
    int choice = 0;
    cout << "\n1 - Add Stock"
        << "\n2 - Display Profit/Loss"
        << "\n3 - Exit Program"
        << "\nEnter your choice: ";
    cin >> choice; 
    while (choice < 1 || choice > 3)
    {
        cout << "Invalid input, please re-enter: ";
        cin >> choice;
    }
    
    return choice;

}


void addStock(vector<StockInfo>& vect)
{
    if (vect.size() < 11)
    {
        StockInfo obj;
        string compName;

        cout << "\nEnter company name: ";
        cin.ignore();
        getline(cin, compName);
        obj.companyName = compName;
        cout << "Number of shares: ";
        cin >> obj.numOfShares;
        cout << "Purchase price? ";
        cin >> obj.purchasePrice;
        cout << "Current price? ";
        cin >> obj.currentPrice;

        obj.currentValue = obj.numOfShares * (obj.currentPrice - obj.purchasePrice);

        vect.push_back(obj);
    }
    else
    {
        cout << "\n\n-----------------------------------";
        cout << "\nSorry, no space left in the stock array";
        cout << "\n-----------------------------------\n\n";

    }

}


void printPortfolio(vector<StockInfo>& vect)
{
    cout << "\n\n\nPortfolio Report\n";
    cout << "=================================\n";
    cout << "Company" << setw(20) << "Profit (Loss)\n";
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect.at(i).companyName << setw(9) << "$" << setw(9) << fixed << setprecision(2) << vect.at(i).currentValue << "\n";  
    }
    cout << "=================================\n";

}


