#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <employee.h>
using namespace std;

class Teacher : public AbstractEmployee{
private:
    string teacherJob;
public:
    Teacher();
    Teacher(string name, int age, string job);
    string getJobName() override;
    void setJobName(string s) override;
    virtual void setProgLang(string s){}
    virtual string getProgLang(){};
    virtual void displayInfo() override {cout<<getName()<<" is "<<getAge()<<" old and has a job in "<<getJobName()<<'\n';}
};
#endif