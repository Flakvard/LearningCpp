#include "factory.h"


DeveloperFactory::DeveloperFactory(/* args */){}
DeveloperFactory::~DeveloperFactory(){}
Employee* DeveloperFactory::createEmployee(){
    return new Developer();
}

TeacherFactory::TeacherFactory(/* args */){}
TeacherFactory::~TeacherFactory(){}

Employee* TeacherFactory::createEmployee(){
    return new Teacher();
}