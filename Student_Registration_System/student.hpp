#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "course.hpp"
#include <vector>
#include <iomanip>


class Student
{
private:
    string studentName;
    int studentID;
    vector<Course> courses;

public:
    Student();
    Student(string, int);

    void setName(string);
    string getName();
    void setStudID(int);
    int getStudID();

    void addCourse();
    double getGPA();
    void printTranscript();
    int getCoursesSize();

};

#endif
