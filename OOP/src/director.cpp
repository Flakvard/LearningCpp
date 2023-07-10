#include <director.h>


EmployeeDirector::EmployeeDirector(/* args */)
{
}

EmployeeDirector::~EmployeeDirector()
{
}

IEmployee* EmployeeDirector::buildBobbyDeveloper(IEmployeeBuilder* teach){
    teach->setName("Bobby 2");
    teach->setAge(25);
    teach->setJobName("Math");
    return teach->build();
}