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
    /* data */
public:
    virtual string getName() = 0;
    virtual int getAge() = 0;
    virtual void setName(string n) = 0;
    virtual void setAge(int a) = 0;
    virtual void setJobName(string s) = 0;
    virtual void setProgLang(string s) = 0;
    virtual string getJobName() = 0;
    virtual string getProgLang() = 0;
    virtual ~IEmployee(){cout<<"Destruct IEmployee\n";} 
};

class AbstractEmployee : public IEmployee
{
private:
    string name;
    int age;
public:
    AbstractEmployee();
    AbstractEmployee(TypeOfEmployee type);
    AbstractEmployee(string n, int a);
    virtual string getName();
    virtual int getAge();
    virtual void setName(string n);
    virtual void setAge(int a);
    virtual void setJobName(string s){}
    virtual void setProgLang(string s){}
    virtual string getJobName(){}
    virtual string getProgLang(){}
    virtual ~AbstractEmployee();
};
#endif