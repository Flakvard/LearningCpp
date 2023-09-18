#include <string>
#include <iostream>

struct studentNode{
    std::string studentName;
    int studentGrade;
    studentNode * next;
};
typedef studentNode * studentCollection;

studentNode* createStudent(std::string name, int grade);
void linkStudent(studentCollection sc, studentNode *student);
void printStudentCollection(studentCollection sc);

int main() {

    studentCollection sc;
    //sc->next = 0;
    studentNode * james = createStudent("James", 12);
    studentNode * fred = createStudent("Fred", 10);
    studentNode * jeff = createStudent("Jeff", 02);
    studentNode * bob = createStudent("Bob", 7);
    sc->next = james;
    james->next = fred;
    fred->next = jeff;
    linkStudent(sc, bob);
    // linkStudent(sc, james);
    // linkStudent(sc, fred);
    // linkStudent(sc, jeff);
    printStudentCollection(sc);

}
void printStudentCollection(studentCollection sc){
    studentNode * loopPtr = sc;
    if(loopPtr->next == NULL) return;

    while (loopPtr->next != NULL)
    {
        std::cout<<loopPtr->next->studentName<<'\n';
        std::cout<<loopPtr->next->studentGrade<<'\n';
        std::cout<<'\n';
        loopPtr = loopPtr->next;
    }

}

studentNode* createStudent(std::string name, int grade){
    studentNode * student = new studentNode;
    student->studentName = name;
    student->studentGrade = grade;
    student->next = NULL;
    return student;

}

void linkStudent(studentCollection sc, studentNode *student){
    studentNode * nodePlacement = sc->next;
    student->next = nodePlacement;
    sc->next = student;

    student = NULL;


}
