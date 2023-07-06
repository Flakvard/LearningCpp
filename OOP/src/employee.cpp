#include "employee.h"

Employee::Employee():name("defalut"), age(0) {}

Employee::Employee(string n, int a)
{
    name = n;
    age = a;
    cout<<"new employee\n";
}

Employee::Employee(string n, int a, TypeOfEmployee type)
{
    name = n;
    age = a;
    switch (type)
    {
    case TypeOfEmployee::TEACHER:
        cout<<"new Teacher employee\n";
        break;

    case TypeOfEmployee::DEVELOPER:
        cout<<"new Developer employee\n";
        break;

    default:
        break;
    }
}

string Employee::getName(){
    return name;
}
int Employee::getAge(){
    return age;
 }
