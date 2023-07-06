#include "developer.h"
Developer::Developer(){
    Employee();
    ProgrammingLanguage = "Pending";
}

Developer::Developer(string n, int a, string ProgramLang) :Employee(n, a){
        ProgrammingLanguage = ProgramLang;
    }


string Developer::getProgLang(){
    return ProgrammingLanguage;
}