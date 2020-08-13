#include <iostream>
using namespace std;
#include <string>

#include "healthProfile.h"


int main()
{

    string choice = "Y";

    HealthProfile obj;
    string userName;
    int userAge, userHeightFeet, userHeightInches;
    double userWeight;

    cout << "Enter a name or X to quit: ";
    getline(cin, userName);

    while (choice != "X" || choice != "x")
    {
        obj.setName(userName);
        cout << "Your age: ";
        cin >> userAge;
        obj.setAge(userAge);

        cout << "Your weight: ";
        cin >> userWeight;
        obj.setWeight(userWeight);

        cout << "Your height - feet: ";
        cin >> userHeightFeet;
        cout << "Your height - inches: ";
        cin >> userHeightInches;
        obj.setHeight(userHeightFeet, userHeightInches);

        obj.printProfile();


        cout << "\n\nEnter a name or X to quit: ";
        cin >> choice;
       
    }

    return 0;
}

