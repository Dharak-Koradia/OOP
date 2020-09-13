#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>
using namespace std;


class Course
{
private: 
    string courseID;
    int credits;
    string grade;

public:
    Course();
    Course(string, int, char);

    void setCourseID();
    string getCourseID();
    void setCredits();
    int getCredits();
    void setGrade();
    char getGrade();

};

#endif 
