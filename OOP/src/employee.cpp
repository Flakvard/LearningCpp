#include "employee.h"

Employee::Employee():name("defalut"), age(0) {}

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
