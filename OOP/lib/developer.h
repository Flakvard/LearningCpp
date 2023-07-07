#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <employee.h>
#include <string>

using namespace std;

class Developer: public IEmployee{
private:
    string ProgrammingLanguage;
public:
    Developer();
    Developer(string n, int a, string ProgramLang);
    virtual ~Developer();
    string getProgLang(); //override;
    // void setProgLang(string s) override;
    // virtual void setJobName(string s) = 0;
    // virtual string getJobName() = 0;
};
#endif