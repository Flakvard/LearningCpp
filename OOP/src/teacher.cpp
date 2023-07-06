#include "teacher.h"

Teacher::Teacher(string name, int age, string job) : Employee(name,age)
{
    teacherJob = job;
}
string Teacher::getJobName(){
    return teacherJob;
}