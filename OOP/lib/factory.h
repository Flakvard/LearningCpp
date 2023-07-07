#ifndef FACTORY_H
#define FACTORY_H

#include "employee.h"
#include "developer.h"
#include "teacher.h"

class EmployeeFactory{
private:
    /* data */
public:
    virtual Employee* createEmployee() = 0;
    virtual ~EmployeeFactory() {}
};


class DeveloperFactory : public EmployeeFactory{
private:
    /* data */
public:
    DeveloperFactory(/* args */);
    ~DeveloperFactory();
    Employee* createEmployee() override;
};

class TeacherFactory : public EmployeeFactory{
private:
    /* data */
public:
    TeacherFactory(/* args */);
    ~TeacherFactory();
    Employee* createEmployee() override;
};


#endif