#include <developer.h>
Developer::Developer(){
    IEmployee();
    ProgrammingLanguage = "Pending";
}

Developer::Developer(string n, int a, string ProgramLang) :IEmployee(n, a){
        ProgrammingLanguage = ProgramLang;
    }


string Developer::getProgLang(){
    return ProgrammingLanguage;
}

void Developer::setProgLang(string s)
{
    ProgrammingLanguage = s;
}

Developer::~Developer()
{
    cout<<"Destructor for dev called\n";
    //delete this;
}
