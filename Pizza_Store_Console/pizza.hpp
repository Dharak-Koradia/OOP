#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <vector>


class Pizza
{
private:
    string customerName;
    char size;
    vector<string> toppings;

public:
    Pizza();

    void setSize(char);
    char getSize();
    string getStringSize();
    void setName(string);
    string getName();
    void addToppings(string);
    void clearToppings();
    double getPrice();
    void display();
};
