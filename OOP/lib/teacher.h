#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "employee.h"
using namespace std;

class Teacher : public Employee{
private:
    string teacherJob;
public:
    Teacher(string name, int age, string job);
    string getJobName();
};
#endif