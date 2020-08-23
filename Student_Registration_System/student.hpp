#include "course.hpp"
#include <vector>

class Student
{
private:
    string studentName;
    int studentID;
    vector<Course> courses;

public:
    Student();
    Student(string, int);

    void setName();
    string getName();
    void setStudID();
    int getStudID();

    void addCourse();
    double getGPA();
    void printTranscript();

}

