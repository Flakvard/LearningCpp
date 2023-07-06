#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "employee.h"
#include <string>

using namespace std;

class Developer: public Employee{
private:
    /* data */
    string ProgrammingLanguage;
public:
    Developer();
    Developer(string n, int a, string ProgramLang);
    string getProgLang();
};
#endif