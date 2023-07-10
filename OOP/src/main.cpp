#include <iostream>
#include <string>
#include <employee.h>
#include <factory.h>
#include <builder.h>
#include <director.h>

using namespace std;

int main(){

    // Create the Teacher Factory and Teacher Builder 
    IEmployeeFactory* TeacherCreator = new TeacherFactory();
    IEmployeeBuilder* BuildTeacher = TeacherCreator->createBuilder();
    BuildTeacher->setName("Bobby");
    BuildTeacher->setAge(23);
    BuildTeacher->setJobName("History");
    IEmployee* Bobby = BuildTeacher->build();
    Bobby->displayInfo(); // output: Bobby is 23 old and has a job in History

    // Create the Teacher Factory and Teacher Builder for directors
    IEmployeeFactory* TeacherBobbyCreator = new TeacherFactory();
    IEmployeeBuilder* BuildBobbyTeacher = TeacherBobbyCreator->createBuilder();
    // Create Director  
    EmployeeDirector* BobbyTeachers = new EmployeeDirector();
    IEmployee* Bobby2 = BobbyTeachers->buildBobbyDeveloper(BuildBobbyTeacher);
    Bobby2->displayInfo(); // output: Bobby 2 is 25 old and has a job in Math

    IEmployeeFactory* DeveloperCreator = new DeveloperFactory();
    IEmployeeBuilder* BuildDeveloper = DeveloperCreator->createBuilder();
    BuildDeveloper->setName("Jacky");
    BuildDeveloper->setAge(33);
    BuildDeveloper->setProgLang("C++");
    IEmployee* Jacky = BuildDeveloper->build();
    Jacky->displayInfo(); // output: Jacky is 33 old and programs in: C++

    // Clean up
    delete Bobby;
    delete TeacherCreator;
    delete BuildTeacher;

    delete Bobby2;
    delete BobbyTeachers; // Director for all Bobbys
    delete TeacherBobbyCreator; // Factory for bobby
    delete BuildBobbyTeacher; // builder for bobby

    delete Jacky;
    delete DeveloperCreator;
    delete BuildDeveloper;


    /************************************************************************************************/
    // COMMENTED OUT
    // OLD way to initialize classes via factory

    // IEmployeeFactory* TeacherCreator = new TeacherFactory();
    // IEmployee* Bobby = TeacherCreator->createEmployee();
    // Bobby->setName("Bobby");
    // Bobby->setAge(23);
    // Bobby->setJobName("History");
    // cout<<Bobby->getName()<<" is "<<Bobby->getAge()<<" old and has a job in "<<Bobby->getJobName()<<'\n';

    // Clean up
    // delete Bobby;
    // delete TeacherCreator;

    // IEmployeeFactory* DeveloperCreator = new DeveloperFactory();
    // Developer* Jacky = dynamic_cast<Developer*>(DeveloperCreator->createEmployee());
    // Jacky->setName("Jacky");
    // Jacky->setAge(33);
    // Jacky->setProgLang("C++");
    // Jacky->displayInfo();
    // cout<<Jacky->getName()<<" is "<<Jacky->getAge()<<" old and programs in: "<<Jacky->getProgLang()<<'\n';

    // Clean up
    // delete DeveloperCreator;
    // delete Jacky;


    /************************************************************************************************/
    // COMMENTED OUT
    // OLD way to initialize simple classes, employee, teacher and developers 

    // AbstractEmployee Bob = AbstractEmployee("Bob",23);
    // cout<<Bob.getName()<<" is "<<Bob.getAge()<<" old\n";
    // AbstractEmployee Jack = AbstractEmployee("Jack",33);
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