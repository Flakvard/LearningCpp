#include <factory.h>


DeveloperFactory::DeveloperFactory(/* args */){}
DeveloperFactory::~DeveloperFactory(){}
IEmployee* DeveloperFactory::createEmployee(){
    return new Developer();
}

TeacherFactory::TeacherFactory(/* args */){}
TeacherFactory::~TeacherFactory(){}

IEmployee* TeacherFactory::createEmployee(){
    return new Teacher();
}