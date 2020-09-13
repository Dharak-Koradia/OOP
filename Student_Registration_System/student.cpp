#include "student.hpp"

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

void Student::setName(string userName)
{
    // cout << "\nEnter your name: ";
    // getline(cin, studentName);
    /*
    while(userName.empty())
    {
        cout << "\nName can't be empty, please re-enter: ";
        getline(cin, userName);
    }
    */
    studentName = userName;
}

string Student::getName()
{
    return studentName;
}

void Student::setStudID(int studID)
{
    // cout << "\nPlease enter student ID (integers): ";
    // cin >> studentID;

    while(studID <= 0)
    {
        cout << "\nInvalid, student ID should be non-negative: ";
        cin >> studID;
    }
    studentID = studID;
}

int Student::getStudID()
{
    return studentID;
}

void Student::addCourse()
{
    int num;
    cout << "\nHow many courses would you like to add?: ";
    cin >> num;
    while (num <= 0)
    {
        cout << "\nSorry, should have at least one class: ";
        cin >> num;
    }

    cin.ignore();
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
        cin.ignore();
    }

}

double Student::getGPA()
{
    double GPA = 0.0;
    int totalPoints = 0;
    int credits = 0;

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses.at(i).getGrade() == 'A')
        {
            totalPoints += (4 * courses.at(i).getCredits());
            credits += courses.at(i).getCredits();
        }
        else if (courses.at(i).getGrade() == 'B')
        {
            totalPoints += (3 * courses.at(i).getCredits());
            credits += courses.at(i).getCredits();
        }
        else if (courses.at(i).getGrade() == 'C')
        {
            totalPoints += (2 * courses.at(i).getCredits());
            credits += courses.at(i).getCredits();
        }
        else if (courses.at(i).getGrade() == 'D')
        {
            totalPoints += (1 * courses.at(i).getCredits());
            credits += courses.at(i).getCredits();
        }
        else
            totalPoints += 0;
    }

    GPA = (double) totalPoints / (double) credits;
    return GPA;

}

void Student::printTranscript()
{
    cout << "\n==================================================="
        << "\nTranscript for " << studentName
        << "\n===================================================";

    cout << "\nCourse" << setw(8) << "Grade";
    for (int i = 0; i < courses.size(); i++)
    {
        cout << "\n"<< courses.at(i).getCourseID() << setw(6) << courses.at(i).getGrade();
    }

    cout << "\n\nGPA: " << fixed << setprecision(2) << getGPA();
    cout << "\n===================================================\n";
}

int Student::getCoursesSize()
{
    return courses.size();
}




