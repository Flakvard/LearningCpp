#include <string>
#include <iostream>

struct studentNode{
    int studentId;
    std::string studentName;
    int studentGrade;
    studentNode * next;
};
typedef studentNode * studentCollection;

studentNode* createStudent(int id, std::string name, int grade);
void linkStudent(studentCollection sc, studentNode *student);
void printStudentCollection(studentCollection sc);
void removeStudent(studentCollection sc, int id);

int main() {

    studentCollection sc;
    studentNode * james = createStudent(1, "James", 12);
    studentNode * fred = createStudent(2,"Fred", 10);
    studentNode * jeff = createStudent(3,"Jeff", 02);
    studentNode * bob = createStudent(4,"Bob", 7);
    studentNode * will = createStudent(5,"Will", 4);
    linkStudent(sc, james);
    linkStudent(sc, fred);
    linkStudent(sc, jeff);
    linkStudent(sc, bob);
    linkStudent(sc, will);
    printStudentCollection(sc);

    removeStudent(sc, 3);
    std::cout<<'\n';
    printStudentCollection(sc);
    std::cout<<'\n';
    removeStudent(sc, 1);
    printStudentCollection(sc);
    std::cout<<'\n';

    // clean up - remove dangling references
    james = 0;
    fred = 0;
    jeff = 0;
    bob = 0;
    will = 0;
}

void removeStudent(studentCollection sc, int id){
    studentNode * loopPtr = sc->next;
    studentNode * placementNode = loopPtr;
    while (loopPtr->next != NULL && id != loopPtr->studentId){
        placementNode = loopPtr;
        loopPtr = loopPtr->next;
    }
    // No node found
    if (loopPtr == NULL){
        return;
    } 
    // last node
    else if (loopPtr->next == NULL && loopPtr->studentId == id){
        // last node in the linked list set to NULL
        placementNode->next = NULL;
        delete loopPtr;
    // inbetween node
    }else if (loopPtr->studentId == id) {
        placementNode->next = loopPtr->next;
        delete loopPtr;
    }

}

void printStudentCollection(studentCollection sc){
    studentNode * loopPtr = sc;

    while (loopPtr->next != NULL){
        std::cout<<loopPtr->next->studentName<<'\t';
        std::cout<<loopPtr->next->studentGrade<<'\n';
        loopPtr = loopPtr->next;
    }

}

studentNode* createStudent(int id, std::string name, int grade){
    studentNode * student = new studentNode;
    student->studentId = id;
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

