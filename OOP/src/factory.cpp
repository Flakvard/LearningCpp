#include <factory.h>

DeveloperFactory::DeveloperFactory(/* args */){}
IEmployeeBuilder* DeveloperFactory::createBuilder(){
    return new DeveloperBuilder();
}

DeveloperFactory *DeveloperFactory::getInstance()
{
    static DeveloperFactory instance;
    return &instance;
}

TeacherFactory::TeacherFactory(/* args */){}
IEmployeeBuilder* TeacherFactory::createBuilder(){
    return new TeacherBuilder();
}

TeacherFactory* TeacherFactory::getInstance()
{ 
    static TeacherFactory instance;
    return &instance;
}

