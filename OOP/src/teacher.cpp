#include <teacher.h>

Teacher::Teacher()
{
    AbstractEmployee();
    teacherJob = "pending";
}
Teacher::Teacher(string n, int a, string job) : AbstractEmployee(n, a)
{
    teacherJob = job;
}
string Teacher::getJobName(){
    return teacherJob;
}

void Teacher::setJobName(string s) {
    teacherJob = s;
}
