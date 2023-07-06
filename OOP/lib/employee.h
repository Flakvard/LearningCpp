#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

enum class TypeOfEmployee {
    DEVELOPER,TEACHER
};

class Employee
{
private:
    string name;
    int age;
public:
    Employee();
    Employee(string n, int a);
    Employee(string n, int a, TypeOfEmployee type);
    virtual string getName();
    virtual int getAge();
};
#endif