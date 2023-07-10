#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <builder.h>
class EmployeeDirector
{
private:
    /* data */
public:
    EmployeeDirector(/* args */);
    ~EmployeeDirector();
    IEmployee* buildBobbyDeveloper(IEmployeeBuilder* teach);
};

#endif