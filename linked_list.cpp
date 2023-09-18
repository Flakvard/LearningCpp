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
    studentNode * james = createStudent("James", 12);
    studentNode * fred = createStudent("Fred", 10);
    studentNode * jeff = createStudent("Jeff", 02);
    studentNode * bob = createStudent("Bob", 7);
    linkStudent(sc, james);
    linkStudent(sc, fred);
    linkStudent(sc, jeff);
    linkStudent(sc, bob);
    printStudentCollection(sc);

}
void printStudentCollection(studentCollection sc){
    studentNode * loopPtr = sc;

    while (loopPtr->next != NULL){
        std::cout<<loopPtr->next->studentName<<'\t';
        std::cout<<loopPtr->next->studentGrade<<'\n';
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

