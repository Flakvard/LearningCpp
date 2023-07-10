#include <factory.h>



DeveloperFactory::DeveloperFactory(/* args */){}
DeveloperFactory::~DeveloperFactory(){ cout<<"Developer Factory desctruct\n";}

IEmployeeBuilder* DeveloperFactory::createBuilder(){
    return new DeveloperBuilder();
}
TeacherFactory::TeacherFactory(/* args */){}
TeacherFactory::~TeacherFactory(){ cout<<"Teacher Factory desctruct\n";}

IEmployeeBuilder* TeacherFactory::createBuilder(){
    return new TeacherBuilder();
}
