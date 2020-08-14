#ifndef employee_h
#define employee_h

#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Employee
{
private:
    string name;
    double hourlyRate, hoursWorked;

public:
    void setName(string);
    void setRate(double);
    void setHours(double);


    string getName();
    double getHrlyRate();
    double getHours();

    void getPay();


};


// Class definitions
void Employee::setName(string userName)
{
    while(userName.empty())
    {
        cout << "Name cannot be blank. Please re-enter: ";
        getline(cin, userName);
    }
    name = userName;
}

void Employee::setRate(double userRate)
{
    while(userRate <= 0)
    {
        cout << "Hourly rate needs to be positive, please re-enter: $";
        cin >> userRate;
    }
    hourlyRate = userRate;
}

void Employee::setHours(double userHours)
{
    while (userHours <= 0)
    {
        cout << "Hours must be positive, please re-enter: ";
        cin >> userHours;
    }

    hoursWorked = userHours;
}


string Employee::getName()
{
    return name;
}

double Employee::getHrlyRate()
{
    return hourlyRate;
}


double Employee::getHours()
{
    return hoursWorked;
}


void Employee::getPay()
{
    double totalPay = 0.0;

    if (hoursWorked > 40)
    {        
        double overTimeHours = hoursWorked - 40;        
        totalPay = ((40 * hourlyRate) +  (hourlyRate * 1.5 * overTimeHours));
        cout << "\n==============================================================";
        cout << "\nGross Pay for " << getName() << ": $" << fixed << setprecision(2) << totalPay;
        cout << "\n==============================================================\n\n";
    }
    else
    {
        totalPay = (hoursWorked * hourlyRate);
        cout << "\n==============================================================";
        cout << "\nGross Pay for " << getName() << ": $" << fixed << setprecision(2) << totalPay;
        cout << "\n==============================================================\n\n";
    }

}

#endif
