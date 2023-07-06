#include <iostream>
#include <string>
#include "./employee.h"
#include "./developer.h"

using namespace std;

int main(){
    cout<<"Hello world\n";
    string hello = "Hello";
    Employee Bob("Bob",23);
    Employee Jack = Employee("Jack",33);

    cout<<Jack.getName()<<" is "<<Jack.getAge()<<" old\n";
    cout<<Bob.getName()<<" is "<<Bob.getAge()<<" old\n";

    Employee Hellen = Employee("Hellen", 43);
    cout<<Hellen.getName()<<" is "<<Hellen.getAge()<<" old\n";
    cout<<Hellen.getName()<<" is "<<Hellen.getAge()<<" old\n";

    Developer Job = Developer("Job",23,"C++");
    cout<<Job.getName()<<" is "<<Job.getAge()<<" old\n";




    return 0;
}