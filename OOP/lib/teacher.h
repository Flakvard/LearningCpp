#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <employee.h>
using namespace std;

class Teacher : public IEmployee{
private:
    string teacherJob;
public:
    Teacher();
    Teacher(string name, int age, string job);
    string getJobName(); //override;
    // void setJobName(string s) override;
    // virtual void setProgLang() = 0;
    // virtual string getProgLang() = 0;
};
#endif