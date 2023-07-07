#include <factory.h>


DeveloperFactory::DeveloperFactory(/* args */){}
DeveloperFactory::~DeveloperFactory(){ cout<<"Developer Factory desctruct\n";}
IEmployee* DeveloperFactory::createEmployee(){
    return new Developer();
}

TeacherFactory::TeacherFactory(/* args */){}
TeacherFactory::~TeacherFactory(){ cout<<"Teacher Factory desctruct\n";}

IEmployee* TeacherFactory::createEmployee(){
    return new Teacher();
}