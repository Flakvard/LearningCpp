#include <teacher.h>

Teacher::Teacher()
{
    IEmployee();
    teacherJob = "pending";
}
Teacher::Teacher(string n, int a, string job) : IEmployee(n, a)
{
    teacherJob = job;
}
string Teacher::getJobName(){
    return teacherJob;
}

void Teacher::setJobName(string s) {
    teacherJob = s;
}
