#include <factory.h>

DeveloperFactory::DeveloperFactory(/* args */){}
IEmployeeBuilder* DeveloperFactory::createBuilder(){
    return new DeveloperBuilder();
}

TeacherFactory::TeacherFactory(/* args */){}
IEmployeeBuilder* TeacherFactory::createBuilder(){
    return new TeacherBuilder();
}
