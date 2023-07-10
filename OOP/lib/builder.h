#ifndef BUILDER_H
#define BUILDER_H

#include <employee.h>
#include <developer.h>
#include <teacher.h>
#include <string>
#include <memory>

using namespace std;

class IEmployeeBuilder
{
public:
    virtual ~IEmployeeBuilder(){}
    virtual void setName(string n) = 0;
    virtual void setAge(int a) = 0;
    virtual void setJobName(string s) = 0;
    virtual void setProgLang(string s) = 0;
    virtual IEmployee* build() = 0;
};


class DeveloperBuilder : public IEmployeeBuilder
{
private:
    IEmployee* dev;
public:
    DeveloperBuilder(/* args */);
    ~DeveloperBuilder(){}
    void setName(string n) override;
    void setAge(int a) override;
    void setJobName(string s) override;
    void setProgLang(string s) override;
    IEmployee* build() override;

};

class TeacherBuilder: public IEmployeeBuilder
{
private:
    IEmployee* Teach;
public:
    TeacherBuilder(/* args */);
    ~TeacherBuilder(){}
    void setName(string n) override;
    void setAge(int a) override;
    void setJobName(string s) override;
    void setProgLang(string s) override;
    IEmployee* build() override;
};

#endif