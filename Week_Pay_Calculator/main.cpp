#include "empolyee.hpp"

int main()
{
    Employee obj;
    string userName;
    double userRate, userHours;
    char choice;

    do 
    {
        cout << "\nEnter employee's name: ";
        getline(cin, userName);

        obj.setName(userName);

        cout << "Enter hours worked: ";
        cin >> userHours;
        obj.setHours(userHours);

        cout << "Enter hourly rate: $";
        cin >> userRate;
        obj.setRate(userRate);

        obj.getPay();

        cout << "\nAnother employee (Y/N): ";
        cin >> choice;
        cin.ignore();

    } while (toupper(choice) != 'N');
    
    
    cout << "\n============";
    cout << "\nGoodbye!";
    cout << "\n============\n\n";
    return 0;
}