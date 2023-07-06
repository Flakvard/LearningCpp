#include <iostream>
#include <string>
#include "./employee.h"
#include "./developer.h"
#include "./teacher.h"

using namespace std;

int main(){
    cout<<"Hello world\n";
    string hello = "Hello";
    Employee Bob("Bob",23);
    cout<<Bob.getName()<<" is "<<Bob.getAge()<<" old\n";
    Employee Jack = Employee("Jack",33,TypeOfEmployee::DEVELOPER);
    cout<<Jack.getName()<<" is "<<Jack.getAge()<<" old\n";


    Teacher Hellen = Teacher("Hellen", 43, "History");
    cout<<Hellen.getName()<<" is "<<Hellen.getAge()<<" old and she is a "<<Hellen.getJobName()<<" teacher\n";

    Developer Job = Developer("Job",23,"C++");
    cout<<Job.getName()<<" is "<<Job.getAge()<<" old and he is a "<<Job.getProgLang()<<" programmer\n";

    Developer* PtrToJob = &Job;
    cout<<PtrToJob->getName()<<'\n'; // same thing Job.getName() but only availabe with virual functions
    cout<<(*PtrToJob).getName()<<'\n'; // same as ->






    return 0;
}