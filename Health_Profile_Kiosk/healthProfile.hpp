#ifndef healthProfile_h
#define healthProfile_h

#include <string>
#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath> 

class HealthProfile
{
private:
    string name;
    int age, height;
    double weight;

public:
    void setName(string);
    void setAge(int);
    void setWeight(double);
    void setHeight(int, int);

    string getName();
    int getAge();
    double getWeight();
    int getHeight();

    double getBMI();
    string getCategory();
    int getMaxHR();
    void printProfile();

};


void HealthProfile::setName(string userName)
{
    while (userName.empty())
    {
        cout << "Name cannot be an empty string. Please re-enter: ";
        getline(cin, userName);
    }

    name = userName;
}

void HealthProfile::setAge(int userAge)
{
    while (userAge <= 0 || userAge > 200)
    {
        cout << "Invalid age. Please re-enter: ";
        cin >> userAge;
    }
    age = userAge; 
}

void HealthProfile::setWeight(double userWeight)
{
    while (userWeight <= 0)
    {
        cout << "Invalid weight, please re-enter: ";
        cin >> userWeight;
    }
    weight = userWeight;
}

void HealthProfile::setHeight(int userFeet, int userInches)
{
    // height should be in total inches
    while (userFeet <= 0)
    {
        cout << "Invalid height in feet, please re-enter: ";
        cin >> userFeet;
    }

    while (userInches < 0)
    {
        cout << "Invalid height in inches, please re-enter: ";
        cin >> userInches;
    }

    height = (userFeet * 12) + userInches;
}

string HealthProfile::getName()
{
    return name;
}

int HealthProfile::getAge()
{
    return age;
}

double HealthProfile::getWeight()
{
    return weight;
}

int HealthProfile::getHeight()
{
    return height;
}

double HealthProfile::getBMI()
{
    double BMI = (weight * 703) / pow(height, 2);
    return BMI;
}

string HealthProfile::getCategory()
{
    if (getBMI() < 18.5)
        return "Underweight";
    else if (getBMI() >= 18.5 && getBMI() < 25)
        return "Normal";
    else if (getBMI() >= 25 && getBMI() < 30)
        return "Overweight";
    else 
        return "Overweight";
}

int HealthProfile::getMaxHR()
{
    return (220 - age);
}

void HealthProfile::printProfile()
{
    cout << "\n====================================";
    cout << "\nHealth profile for " << name;
    cout << "\nBMI: " << fixed << setprecision(1) << getBMI();
    cout << "\nBMI Category: " << getCategory();
    cout << "\nMax heart rate: " << getMaxHR();
    cout << "\n====================================";
}


#endif
