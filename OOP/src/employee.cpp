#include "employee.h"

Employee::Employee():name("default"), age(0) {}

Employee::Employee(TypeOfEmployee type) :name("Default"), age(0) {
    if (type == TypeOfEmployee::DEVELOPER)
    {
        cout<<"new Developer employee\n";
    }else if (type == TypeOfEmployee::TEACHER)
    {
        cout<<"new Teacher employee\n";
    }
        cout<<"New employee";
}
Employee::Employee(string n, int a)
{
    name = n;
    age = a;
    cout<<"new employee\n";
}

string Employee::getName(){
    return name;
}
int Employee::getAge(){
    return age;
 }
