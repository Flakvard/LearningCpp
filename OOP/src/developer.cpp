#include "developer.h"

Developer::Developer(string name, int age, string ProgramLang)
{
    Employee(name, age);
    ProgrammingLanguage = ProgramLang;
}