#include "student.hpp"
#include <iomanip>

Student::Student()
{
    studentName = "No name assigned!";
    studentID = -1;
}

Student::Student(string studName, int studID)
{
    studentName = studName;
    studentID = studID;
}

void Student::setName()
{
    cout << "\nEnter your name: ";
    getline(cin, studentName);

    while(studentName.empty())
    {
        cout << "\nName can't be empty, please re-enter: ";
        getline(cin, studentName);
    }
}

string Student::getName()
{
    return studentName;
}

void Student::setStudID()
{
    cout << "\nPlease enter student ID (integers): ";
    cin >> studentID;

    while(studentID <= 0)
    {
        cout << "\nInvalid, student ID should be non-negative: ";
        cin >> studentID;
    }
}

int Student::getStudID()
{
    return studentID;
}

void Student::addCourse()
{
    int num;
    cout << "\nHow many courses do you have?: ";
    cin >> num;
    while (num <= 0)
    {
        cout << "\nSorry, should have at least one class: ";
        cin >> num;
    }

    // set all the courses
    for (int i = 1; i <= num; i++)
    {
        cout << "\n------------------------------------";
        cout << "\nCourse " << i << "\n";
        Course obj;

        obj.setCourseID();
        obj.setCredits();
        obj.setGrade();
        cout << "\n------------------------------------";

        courses.push_back(obj);
    }

}

double Student::getGPA()
{
    double GPA = 0;

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses.at(i).getGrade() == 'A')
            GPA += 4;
        else if (courses.at(i).getGrade() == 'B')
            GPA += 3;
        else if (courses.at(i).getGrade() == 'C')
            GPA += 2;
        else if (courses.at(i).getGrade() == 'D')
            GPA += 1;
        else
            GPA += 0;
    }

    GPA = GPA / courses.size();
    return GPA;
}

void Student::printTranscript()
{
    cout << "\n-------------------------------------------------"
        << "\nTranscript for " << studentName
        << "\n-------------------------------------------------";

    cout << "\nCourses: ";
    for (int i = 0; i < courses.size(); i++)
    {
        cout << "\nCourse ID: " << courses.at(i).getCourseID();
    }

    cout << "\n\nGPA: " << fixed << setprecision(2) << getGPA();
    cout << "\n-------------------------------------------------\n";
}





