#include "pizza.hpp"

Pizza::Pizza()
{
    customerName = "No customer name";
    size = 'X';
}

void Pizza::setSize(char sizeChoice)
{
    while(toupper(sizeChoice) != 'S' && toupper(sizeChoice) != 'M' && toupper(sizeChoice) != 'L')
    {
        cout << "\nInvalid pizza size, please re-enter (S,M,L): ";
        cin >> sizeChoice;
    }
    size = sizeChoice;
}

char Pizza::getSize()
{
    return toupper(size);
}

string Pizza::getStringSize()
{
    if (getSize() == 'S')
        return "Small";
    else if (getSize() == 'M')
        return "Medium";
    else
        return "Large";
}

void Pizza::setName(string userName)
{
    while (userName.empty())
    {
        cout <<"\nName cannot be a space, please re-enter: ";
        getline(cin, userName);
    }

    customerName = userName;
}

string Pizza::getName()
{
    return customerName;
}

void Pizza::addToppings(string userToppings)
{
    if (userToppings.empty() == false)
    {
        toppings.push_back(userToppings);
    }
}

void Pizza::clearToppings()
{
    toppings.clear();
}


double Pizza::getPrice()
{
    double price = 0;
    // calculate the regular price, first
    if (toupper(size) == 'S')
    {
        price += 10;
    }
    else if (toupper(size) == 'M')
    {
        price += 14;
    }
    else
    {
        price += 17;
    }
    
    // Now, add price for the toppings
    price = price + (toppings.size() * 2);

    return price;
}


void Pizza::display()
{
    cout << "\n=========================================";
    cout << "\nCustomer name: " << customerName;
    cout << "\n" << getStringSize() << " pizza with " << toppings.size() << " toppings";

    if (toppings.size() != 0)
    {
        cout << "\nToppings: ";
        for (int i = 0; i < toppings.size(); i++)
        {
            if (i >= 0 && i < toppings.size() - 1)
            {
                cout << toppings.at(i) << ", ";
            }
            else
            {
                cout << toppings.at(i) << " ";
            }
            
        }
    }
    cout << "\nPrice: $" << fixed << setprecision(2) << getPrice();
    cout << "\n=========================================\n\n";
}
