#include <employee.h>

IEmployee::IEmployee():name("default"), age(0) {}

IEmployee::IEmployee(TypeOfEmployee type) :name("Default"), age(0) {
    if (type == TypeOfEmployee::DEVELOPER)
    {
        cout<<"new Developer employee\n";
    }else if (type == TypeOfEmployee::TEACHER)
    {
        cout<<"new Teacher employee\n";
    }
        cout<<"New employee";
}
IEmployee::IEmployee(string n, int a)
{
    name = n;
    age = a;
    cout<<"new employee\n";
}

string IEmployee::getName(){
    return name;
}
int IEmployee::getAge(){
    return age;
 }

 void IEmployee::setName(string n){
    name = n;
 }

 void IEmployee::setAge(int a){
    age = a;
 }

 IEmployee::~IEmployee()
 {
    cout<<"Destructor for "<<IEmployee::getName()<<" employee called\n";
    // delete this;
 }
