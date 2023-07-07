#include <iostream>
#include <string>
#include <employee.h>
#include <developer.h>
#include <teacher.h>
#include <factory.h>

using namespace std;

int main(){

    IEmployeeFactory* TeacherCreator = new TeacherFactory();
    IEmployee* Bobby = TeacherCreator->createEmployee();
    Bobby->setName("Bobby");
    Bobby->setAge(23);
    Bobby->setJobName("History");
    cout<<Bobby->getName()<<" is "<<Bobby->getAge()<<" old and has a job in "<<Bobby->getJobName()<<'\n';

    // Clean up
    delete TeacherCreator;
    delete Bobby;

    IEmployeeFactory* DeveloperCreator = new DeveloperFactory();
    Developer* Jacky = dynamic_cast<Developer*>(DeveloperCreator->createEmployee());
    Jacky->setName("Jacky");
    Jacky->setAge(33);
    Jacky->setProgLang("C++");
    cout<<Jacky->getName()<<" is "<<Jacky->getAge()<<" old and programs in: "<<Jacky->getProgLang()<<'\n';

    // Clean up
    delete DeveloperCreator;
    delete Jacky;

    // instanciate 

    // IEmployee Bob = IEmployee("Bob",23);
    // cout<<Bob.getName()<<" is "<<Bob.getAge()<<" old\n";
    // IEmployee Jack = IEmployee("Jack",33);
    // cout<<Jack.getName()<<" is "<<Jack.getAge()<<" old\n";
    // Teacher Hellen = Teacher("Hellen", 43, "History");
    // cout<<Hellen.getName()<<" is "<<Hellen.getAge()<<" old and she is a "<<Hellen.getJobName()<<" teacher\n";
    // Developer Job = Developer("Job",23,"C++");
    // cout<<Job.getName()<<" is "<<Job.getAge()<<" old and he is a "<<Job.getProgLang()<<" programmer\n";
    // Developer* PtrToJob = &Job;
    // cout<<PtrToJob->getName()<<'\n'; // same thing Job.getName() but only availabe with virual functions
    // cout<<(*PtrToJob).getName()<<'\n'; // same as ->
    // Developer* DevPointer = new Developer();
    // cout<<DevPointer->getAge()<<'\n';
    // cout<<DevPointer->getName()<<'\n';
    // DevPointer->setAge(23);
    // DevPointer->setName("Simon");
    // cout<<DevPointer->getName()<<'\n';
    // cout<<DevPointer->getAge()<<'\n';
    // delete DevPointer;
    // cout<<DevPointer->getAge()<<'\n';


    return 0;
}