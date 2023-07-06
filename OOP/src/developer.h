#include "employee.h"
#include <string>
using namespace std;

class Developer: public Employee
{
private:
    /* data */
    string ProgrammingLanguage;
public:
    Developer(string name, int age, string ProgramLang);
    string getProgLang();
};
