#include <string>
#include <iostream>

struct studentLinkedList{
    std::string studentName;
    int studentGrade;
    studentLinkedList * next;
};
typedef studentLinkedList * studentCollection;

studentLinkedList* createStudent(std::string name, int grade);

int main() {

    studentCollection sc;
    studentLinkedList * james = createStudent("James", 12);
    sc->next = james;
    james = NULL;
    std::cout<<sc->next->studentName<<'\n';

}

studentLinkedList* createStudent(std::string name, int grade){
    studentLinkedList * student = new studentLinkedList;
    student->studentName = name;
    student->studentGrade = grade;
    return student;

}
void linkTester(){

}