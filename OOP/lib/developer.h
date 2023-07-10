#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <employee.h>
#include <string>

using namespace std;

class Developer: public AbstractEmployee{
private:
    string ProgrammingLanguage;
public:
    Developer();
    Developer(string n, int a, string ProgramLang);
    virtual ~Developer(){}
    string getProgLang() override;
    void setProgLang(string s) override;
    virtual void setJobName(string s){}
    virtual string getJobName(){}
    virtual void displayInfo() override {cout<<getName()<<" is "<<getAge()<<" old and programs in: "<<getProgLang()<<'\n';}
};
#endif