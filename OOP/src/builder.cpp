#include <builder.h>



DeveloperBuilder::DeveloperBuilder(/* args */)
{
    dev = new Developer();
}

DeveloperBuilder::~DeveloperBuilder()
{
    cout<<"Destruct DeveloperBuilder\n";
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
    return dev;
}


TeacherBuilder::TeacherBuilder(/* args */)
{
    Teach = new Teacher();
}

TeacherBuilder::~TeacherBuilder()
{
    cout<<"Destruct TeacherBuilder\n";
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
    return Teach;
}
