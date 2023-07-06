#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    int age;
public:
    Employee();
    Employee(string n, int a);
    virtual string getName();
    virtual int getAge();
};
#endif