#include "course.hpp"

Course::Course()
{
    courseID = "No course";
    credits = -1;
    grade = 'Z';
}

Course::Course(string crsID, int units, char letterGrade)
{
    courseID = crsID;
    credits = units;
    grade = letterGrade;
}

void Course::setCourseID()
{
    cout << "\nPlease enter the course ID: ";
    getline(cin, courseID);

    while(courseID.empty())
    {
        cout << "\nCourse ID can't be empty, please re-enter: ";
        getline(cin, courseID);
    }
}

string Course::getCourseID()
{
    return courseID;
}

void Course::setCredits()
{
    cout << "\nPlease enter the course credits: ";
    cin >> credits;

    while(credits <= 0)
    {
        cout << "\nCredits have to be non-negative, please re-enter the credits: ";
        cin >> credits;
    }
}

int Course::getCredits()
{
    return credits;
}

void Course::setGrade()
{
    cout << "\nPlease enter a letter grade (A-F): ";
    cin >> grade;

    while (toupper(grade[0]) != 'A' && toupper(grade[0]) != 'B' && toupper(grade[0]) != 'C' && toupper(grade[0]) != 'D' && toupper(grade[0]) != 'F')
    {
        cout << "\nInvalid grade, please re-enter: ";
        cin >> grade;
    }
    
    /*
    while (true)
    {
        try 
        {
            cout << "\nEnter a char: ";
            cin >> grade;


          

            if (grade.size() > 1)
                throw grade;
        }
        catch (...)
        {
            cout << "\nSorry, only one character is allowed in a letter grade (A-F).";
        }

        if (grade.size() == 1)
            break;

    }
    */

}

char Course::getGrade()
{
    return toupper(grade[0]);
}







