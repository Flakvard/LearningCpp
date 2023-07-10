#ifndef FACTORY_H
#define FACTORY_H

#include <employee.h>
#include <developer.h>
#include <teacher.h>
#include <builder.h>

class IEmployeeFactory{
private:
    /* data */
public:
    virtual IEmployeeBuilder* createBuilder() = 0;
    virtual ~IEmployeeFactory() {}
};


class DeveloperFactory : public IEmployeeFactory{
private:
    /* data */
public:
    DeveloperFactory(/* args */);
    ~DeveloperFactory(){}
    IEmployeeBuilder* createBuilder() override;
};

class TeacherFactory : public IEmployeeFactory{
private:
    /* data */
public:
    TeacherFactory(/* args */);
    ~TeacherFactory(){}
    IEmployeeBuilder* createBuilder() override;
};


#endif