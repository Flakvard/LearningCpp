# Object Oriented in C++

## Implemented four pillars of OO
    [x] Encapsulation:
            - Classes header files defined inside lib dir
            - Source C++ files declared inside src dir
            - Object files compiled inside build dir
    [x]  Inheritance:
            class IEmployee
                class AbstractEmployee
                    class Developer
                    class Teacher
            class IEmployeeFactory
                    class DeveloperFactory
                    class TeacherFactory
    [x]  Abstraction/interface:
            class IEmployee
            class AbstractEmployee
            class IEmployeeFactory
    [x]  Polymorhpish:
            class IEmployee
            class IEmployeeFactory
# Design Patterns 
## Factory for employees
Possible to add new type of employees and 
inherit from abstract employee class. 
Right now there are Teacher, Developers
that you can inherit from AbstractEmployee class 

## Abstract Factory 
Report builder 


## Builder for employees, Teachers and Developers
A class that does the building/construction for 
Teachers and Developers. 


## Singleton 
Implement at singleton class and namespace
as a global variable for the program. 
