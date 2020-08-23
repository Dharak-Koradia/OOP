#include "pizza.hpp"

// function prototypes
void summary(vector<Pizza>&);

int main()
{

    vector<Pizza> pizzaOrders;

    int choice;
    cout << "\n\n1 - New Order"
        << "\n2 - Show all orders"
        << "\n3 - Exit"
        << "\nEnter choice: ";
    cin >> choice;

    while (choice == 1 || choice == 2)
    {
        if (choice == 1)
        {
            Pizza obj;
            char pizzaSize;
            string toppingChoice = "Y";
            string custName;

            cout << "\n\nEnter size (S, M, L): ";
            cin >> pizzaSize;
            obj.setSize(pizzaSize);

            
            cin.ignore();
            cout << "Enter a topping, enter x when done: ";
            getline(cin, toppingChoice);
            while (toppingChoice != "x" && toppingChoice != "X")
            {
                obj.addToppings(toppingChoice);
                cout << "Enter a topping, enter x when done: ";
                getline(cin, toppingChoice);
            }

            cout << "\nEnter customer name: ";
            getline(cin, custName);
            obj.setName(custName);

            pizzaOrders.push_back(obj);

            cout << "\n\nYOUR ORDER: ";
            obj.display();
        }
        else
        {
            cout << "\n\n______________________________________________________________";
            for (int i = 0; i < pizzaOrders.size(); i++)
            {
                pizzaOrders.at(i).display();
            }
            cout << "______________________________________________________________\n\n";
        }
        

        cout << "\n\n1 - New Order"
            << "\n2 - Show all orders"
            << "\n3 - Exit"
            << "\nEnter choice: ";
        cin >> choice;

    }
    summary(pizzaOrders);
    cout << "\n-------------------";
    cout << "\nGOODBYE!";
    cout << "\n-------------------\n";

    return 0;
}


void summary(vector<Pizza>& vect)
{
    double totalSales = 0;

    cout << "\n----------"
        << "\nSummary"
        << "\n----------\n";
    cout << "Customer" << setw(6) << "Size" << setw(8) << "Price\n";
    
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect.at(i).getName() << setw(8) << vect.at(i).getSize() << setw(5) 
        << fixed << setprecision(2) << "$" <<  vect.at(i).getPrice() << "\n"; 
        totalSales += vect.at(i).getPrice();
    }

    
    cout << "\n\nTotal sales: $" << fixed << setprecision(2) << totalSales << "\n";
    cout << "_________________________________________________\n\n";

}
