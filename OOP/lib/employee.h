#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

enum class TypeOfEmployee {
    DEVELOPER,TEACHER
};

class IEmployee
{
private:
    string name;
    int age;
public:
    IEmployee();
    IEmployee(TypeOfEmployee type);
    IEmployee(string n, int a);
    virtual string getName();
    virtual int getAge();
    virtual void setName(string n);
    virtual void setAge(int a);
    // virtual void setJobName(string s) = 0;
    // virtual void setProgLang(string s) = 0;
    // virtual string getJobName() = 0;
    // virtual string getProgLang() = 0;
    virtual ~IEmployee();
};
#endif