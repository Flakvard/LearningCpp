#include <builder.h>



DeveloperBuilder::DeveloperBuilder(/* args */)
{
    dev = new Developer();
}

void DeveloperBuilder::setName(string n){
    dev->setName(n);
}

void DeveloperBuilder::setAge(int a)
{
    dev->setAge(a);
}

void DeveloperBuilder::setJobName(string s)
{
}

void DeveloperBuilder::setProgLang(string s)
{
    dev->setProgLang(s);
}

IEmployee* DeveloperBuilder::build()
{
    IEmployee* builtDeveloper = dev;
    dev = new Developer(); // Create a new instance for the next build
    return builtDeveloper;
}


TeacherBuilder::TeacherBuilder(/* args */)
{
    Teach = new Teacher();
}

void TeacherBuilder::setName(string n){
    Teach->setName(n);
}

void TeacherBuilder::setAge(int a)
{
    Teach->setAge(a);
}

void TeacherBuilder::setJobName(string s)
{
    Teach->setJobName(s);
}

void TeacherBuilder::setProgLang(string s)
{
}

IEmployee* TeacherBuilder::build()
{
    IEmployee* builtTeacher = Teach;
    Teach = new Teacher(); // Create a new instance for the next build
    return builtTeacher;
}
