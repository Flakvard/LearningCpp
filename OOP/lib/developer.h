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
    string getProgLang() override;
    void setProgLang(string s) override;
    void setJobName(string s){}
    string getJobName(){}
};
#endif