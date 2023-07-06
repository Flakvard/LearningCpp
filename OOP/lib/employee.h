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
    Employee(TypeOfEmployee type);
    Employee(string n, int a);
    // virtual void createEmployee();
    virtual string getName();
    virtual int getAge();
    virtual void setName(string n);
    virtual void setAge(int a); 
    //Employee* CreateEmployees(TypeOfEmployee); 
    virtual ~Employee();
};
#endif