#ifndef FACTORY_H
#define FACTORY_H

#include <employee.h>
#include <developer.h>
#include <teacher.h>

class IEmployeeFactory{
private:
    /* data */
public:
    virtual IEmployee* createEmployee() = 0;
    virtual ~IEmployeeFactory() {}
};


class DeveloperFactory : public IEmployeeFactory{
private:
    /* data */
public:
    DeveloperFactory(/* args */);
    ~DeveloperFactory();
    IEmployee* createEmployee() override;
};

class TeacherFactory : public IEmployeeFactory{
private:
    /* data */
public:
    TeacherFactory(/* args */);
    ~TeacherFactory();
    IEmployee* createEmployee() override;
};


#endif