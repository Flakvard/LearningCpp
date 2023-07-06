#include "teacher.h"

Teacher::Teacher()
{
    Employee();
    teacherJob = "pending";
}
Teacher::Teacher(string n, int a, string job) : Employee(n, a)
{
    teacherJob = job;
}
string Teacher::getJobName(){
    return teacherJob;
}