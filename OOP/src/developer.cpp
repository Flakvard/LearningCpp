#include <developer.h>
Developer::Developer(){
    AbstractEmployee();
    ProgrammingLanguage = "Pending";
}

Developer::Developer(string n, int a, string ProgramLang) :AbstractEmployee(n, a){
        ProgrammingLanguage = ProgramLang;
    }


string Developer::getProgLang(){
    return ProgrammingLanguage;
}

void Developer::setProgLang(string s)
{
    ProgrammingLanguage = s;
}
