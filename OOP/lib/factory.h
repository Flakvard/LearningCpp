#ifndef FACTORY_H
#define FACTORY_H

#include <employee.h>
#include <developer.h>
#include <teacher.h>

class IEmployeeFactory{
private:
    /* data */
public:
    virtual AbstractEmployee* createEmployee() = 0;
    virtual ~IEmployeeFactory() { cout<<"Employee Factory desctruct\n";}
};


class DeveloperFactory : public IEmployeeFactory{
private:
    /* data */
public:
    DeveloperFactory(/* args */);
    ~DeveloperFactory();
    AbstractEmployee* createEmployee() override;
};

class TeacherFactory : public IEmployeeFactory{
private:
    /* data */
public:
    TeacherFactory(/* args */);
    ~TeacherFactory();
    AbstractEmployee* createEmployee() override;
};


#endif