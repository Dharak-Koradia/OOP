#include "healthProfile.hpp"

#include <iostream>
#include <string>
using namespace std;


int main()
{

    string choice = "Y";

    HealthProfile obj;
    int userAge, userHeightFeet, userHeightInches;
    double userWeight;

    cout << "\n\nEnter a name or X to quit: ";
    getline(cin, choice);

    while (choice != "X" && choice != "x")
    {
        obj.setName(choice);
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
        cin.ignore();
        getline(cin, choice);
       
    }

    cout << "\n================";
    cout << "\nGOODBYE!";
    cout << "\n================\n\n";

    return 0;
}
