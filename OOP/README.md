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
that you can inherit from AbstractEmployee class. 


## Builder for employees, Teachers and Developers
A class that does the building/construction for 
Teachers and Developers. 
Construction for Developers and Teachers are now moved into 
IEmployeeBuilder called DeveloperBuilder() and TeacherBuilder()
DeveloperBuilder() and TeacherBuilder() are inside 
DeveloperFactory and TeacherFactory in base class IEmployeeFactory

## Director for Builder
Create standard template for builders. 
Implemented a director for Bobby teacher.
Does not make intiuative sense in this regard, but it works.
IEmployee* buildBobbyDeveloper(IEmployeeBuilder* teach);

## Singleton 
Implement at singleton class and namespace
as a global variable for the program. 
Not yet implemented

# Here's a breakdown of what's happening:
The main function creates different employees using factories and builders. 


## Creating a Teacher Employee:
- First, a TeacherFactory is created using IEmployeeFactory* TeacherCreator = new TeacherFactory();.
- Then, a TeacherBuilder is obtained from the factory using IEmployeeBuilder* BuildTeacher = TeacherCreator->createBuilder();.
- The builder is used to set the desired attributes of the employee, such as name, age, and job name, using the setter methods.
- The build() method is called on the builder to create the IEmployee* Bobby object.
- Finally, Bobby->displayInfo() is called to display the information of the teacher employee.
- this is done again with Timmy using the same builder and factory.
```c++
    // Create the Teacher Factory and Teacher Builder 
    IEmployeeFactory* TeacherCreator = new TeacherFactory();
    IEmployeeBuilder* BuildTeacher = TeacherCreator->createBuilder();
    BuildTeacher->setName("Bobby");
    BuildTeacher->setAge(23);
    BuildTeacher->setJobName("History");
    IEmployee* Bobby = BuildTeacher->build();
    Bobby->displayInfo(); // output: Bobby is 23 old and has a job in History

    BuildTeacher->setName("Timmy");
    BuildTeacher->setAge(26);
    BuildTeacher->setJobName("Computer Science");
    IEmployee* Timmy = BuildTeacher->build();
    Timmy->displayInfo(); // output: Timmy is 26 old and has a job in Computer Science
    Bobby->displayInfo(); // output: Bobby is 23 old and has a job in History

```
## Creating a Teacher Employee with Director:
- An EmployeeDirector named BobbyTeachers is created to simplify the creation process.
- The buildBobbyDeveloper method of the BobbyTeachers director is called, passing the BuildTeacher builder from eariler.
- The director takes the builder and sets additional attributes to create a specific kind of employee.
- The resulting IEmployee* Bobby2 object is displayed using Bobby2->displayInfo().
```c++
// Create Director  
    EmployeeDirector* BobbyTeachers = new EmployeeDirector();
    IEmployee* Bobby2 = BobbyTeachers->buildBobbyDeveloper(BuildTeacher);
    Bobby2->displayInfo(); // output: Bobby 2 is 25 old and has a job in Math
```

## Creating a Developer Employee:
Similar steps are followed as in the creation of the teacher employee, but using a DeveloperFactory and DeveloperBuilder.
The builder is used to set the name, age, and programming language attributes of the employee.
The resulting IEmployee* Jacky object is displayed using Jacky->displayInfo().
```c++
    IEmployeeFactory* DeveloperCreator = new DeveloperFactory();
    IEmployeeBuilder* BuildDeveloper = DeveloperCreator->createBuilder();
    BuildDeveloper->setName("Jacky");
    BuildDeveloper->setAge(33);
    BuildDeveloper->setProgLang("C++");
    IEmployee* Jacky = BuildDeveloper->build();
    Jacky->displayInfo(); // output: Jacky is 33 old and programs in: C++
```
## Cleaning up:
All the dynamically allocated objects are deleted to free the memory.

```c++
    // Clean up
    delete Bobby;
    delete TeacherCreator;
    delete BuildTeacher;

    delete Bobby2;
    delete BobbyTeachers; // Director for all Bobbys builders

    delete Jacky;
    delete DeveloperCreator;
    delete BuildDeveloper;

```
