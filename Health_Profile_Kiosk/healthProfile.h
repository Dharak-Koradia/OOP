#ifndef healthProfile_h
#define healthProfile_h

// #pragma once
#include <string>
using namespace std;

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

#endif /* healthProfile_h */
