#include <string>
#include <iostream>

struct studentLinkedList{
    std::string studentName;
    int studentGrade;
    studentLinkedList * next;
};
typedef studentLinkedList * studentCollection;

int main() {

    studentCollection sc;
    studentLinkedList * james = new studentLinkedList;
    james->studentName = "James";
    james->studentGrade = 12;
    sc->next = james;
    std::cout<<sc->next->studentName<<'\n';
    

}

void linkTester(){

}