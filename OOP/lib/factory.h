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
    DeveloperFactory(/* args */);
public:
    ~DeveloperFactory(){}
    IEmployeeBuilder* createBuilder() override;
    static DeveloperFactory* getInstance();
};

class TeacherFactory : public IEmployeeFactory{
private:
    /* data */
    TeacherFactory(/* args */);
public:
    ~TeacherFactory(){}
    IEmployeeBuilder* createBuilder() override;
    static TeacherFactory* getInstance();
};


#endif