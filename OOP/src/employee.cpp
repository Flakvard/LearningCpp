#include <employee.h>

AbstractEmployee::AbstractEmployee():name("default"), age(0) {}

AbstractEmployee::AbstractEmployee(TypeOfEmployee type) :name("Default"), age(0) {
    if (type == TypeOfEmployee::DEVELOPER)
    {
        cout<<"new Developer employee\n";
    }else if (type == TypeOfEmployee::TEACHER)
    {
        cout<<"new Teacher employee\n";
    }
        cout<<"New employee";
}
AbstractEmployee::AbstractEmployee(string n, int a)
{
    name = n;
    age = a;
    cout<<"new employee\n";
}

string AbstractEmployee::getName(){
    return name;
}
int AbstractEmployee::getAge(){
    return age;
 }

 void AbstractEmployee::setName(string n){
    name = n;
 }

 void AbstractEmployee::setAge(int a){
    age = a;
 }

 AbstractEmployee::~AbstractEmployee()
 {
    cout<<"Destructor for "<<AbstractEmployee::getName()<<" employee called\n";
    // delete this;
 }
