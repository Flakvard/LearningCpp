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
    string getName();
    int getAge();
};
#endif