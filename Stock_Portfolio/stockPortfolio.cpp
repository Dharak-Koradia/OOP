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
void sellStock(vector<StockInfo>&, int);

// Global variable to count the total money
double remainingMoney;

int main()
{
    cout << "\n";
    remainingMoney = 0.0;
    vector<StockInfo> vect;
    int choice = menuOption();

    while (choice != 4)
    {

        switch (choice)
        {
        case 1:
            addStock(vect);
            break;

        case 2:
            int remove;
            cout << "\nEnter the number of the stock you want to remove: ";
            cin >> remove;
            sellStock(vect, remove);
            break;

        case 3:
            printPortfolio(vect);
            break;
        
        default:
            break;
        }

        choice = menuOption();
    }
    
    cout << "\n__________________________________________________________"
        << "\nSUMMARY\n";
    printPortfolio(vect);
    cout << "\nMoney used in share transactions: $" << remainingMoney;
    cout << "\n__________________________________________________________"
        << "\nGoodbye!\n\n";

    return 0;
}



int menuOption()
{
    int choice = 0;
    cout << "\n1 - Add Stock"
        << "\n2 - Sell Stock"
        << "\n3 - Display Potential Profit/Loss"
        << "\n4 - Exit Program"
        << "\nEnter your choice: ";
    cin >> choice; 
    while (choice < 1 || choice > 4)
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
        cout << "Purchase price? $";
        cin >> obj.purchasePrice;
        cout << "Current price? $";
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
    cout  << setw(1) << "  Company" << setw(30) << "Potential Profit (Loss)\n";
    int j = 1;
    for (int i = 0; i < vect.size(); i++)
    {
        cout << j << setw(8) << vect.at(i).companyName << setw(9) << "$" << setw(9) << fixed << setprecision(2) << vect.at(i).currentValue << "\n";  
        j++;
    }
    cout << "=================================\n";
}


void sellStock(vector<StockInfo>& vect, int stockNum)
{
    if (vect.size() > 0)
    {
        int removeStock = stockNum;
        printPortfolio(vect);
        cout << "\n";
        while (removeStock < 1 || removeStock > vect.size())
        {
            cout << "Invalid stock number, please re-enter: ";
            cin >> removeStock;
        }

        remainingMoney += vect.at(removeStock - 1).currentValue;

        // subract 1 from the original removeStock to access the index position
        vect.erase(vect.begin() + removeStock - 1);

        cout << "\n\nPortfolio after deleting the stock " << removeStock << ":\n\n";
        printPortfolio(vect);

        cout << "\n-------------------------------------------------";
        cout << "\nTotal money used in transactions: $" << remainingMoney;
        cout << "\n-------------------------------------------------\n";


    }
    else
    {
        cout << "\n\nSorry, you don't have any stocks in your portfolio\n\n";
    }

}

