#include <iostream>
#include <string>

struct studentRecord{
    int id;
    int grade;
    std::string name;

    studentRecord(){
        int id = 0;
        int grade = 0;
        std::string name = "";
    }
    studentRecord(int id, int grade,std::string name) :id(id), grade(grade),name(name){}
    void printStudent(){
    std::cout<<"ID: "
                <<id
                <<"\nName: "
                <<name
                <<"\nGrade: "
                <<grade
                <<'\n';
    }

};

class studentCollection
{
private:
    struct studentNode
    {
        studentRecord studentData;
        studentNode* next;
    };
public:
    studentCollection(/* args */);
    void addRecord(studentRecord studentData);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(studentRecord student);
    void printRecords();
    ~studentCollection();
    studentCollection& operator=(const studentCollection& rhs);
private:
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listHead);
    studentList copyStudentCollection(const studentList& original);

};

studentCollection::studentCollection(/* args */)
{
    studentCollection::_listHead = NULL;
}

void studentCollection::addRecord(studentRecord studentData)
{
    studentNode * newNode = new studentNode;
    newNode->studentData = studentData;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum)
{
    studentNode * loopPtr = _listHead;
    while (loopPtr->next != NULL && loopPtr->studentData.id != idNum){
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL){
        studentRecord dummyRecord;
        return dummyRecord;
    }else{
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(studentRecord student){

    studentNode * loopPtr = _listHead;
    studentNode * trailing = loopPtr;
    while (loopPtr != NULL && loopPtr->studentData.id != student.id){
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    // No student found in StudentCollection
    if (loopPtr == NULL){
        return;
    // End of the linked list
    }
    if (loopPtr->next == NULL){
        trailing->next = NULL;
        delete loopPtr;
    // First of the linked list
    }else if(trailing==loopPtr){
        delete loopPtr;
        _listHead = loopPtr->next;
    // Middle of the linked list
    }else{
        trailing->next = loopPtr->next; 
        delete loopPtr;
    }
}

void studentCollection::printRecords(){
    studentNode * loopPtr = _listHead;
    if (loopPtr == NULL){
        std::cout<<"Nothing inside list\n";
        return;
    }
    while (loopPtr != NULL){
        std::cout<<"ID: "
                 <<loopPtr->studentData.id
                 <<"\nName: "
                 <<loopPtr->studentData.name
                 <<"\nGrade: "
                 <<loopPtr->studentData.grade
                 <<'\n';
        loopPtr = loopPtr->next;
    }
    if (loopPtr != NULL){
        std::cout<<"ID: "
                 <<loopPtr->studentData.id
                 <<"\nName: "
                 <<loopPtr->studentData.name
                 <<"\nGrade: "
                 <<loopPtr->studentData.grade
                 <<'\n';
    }
    
}

void studentCollection::deleteList(studentList &listHead){
    studentNode * loopPtr = listHead;
    while (loopPtr != NULL){
        studentNode * deleteNode = loopPtr;
        loopPtr = loopPtr->next;
        delete deleteNode;
    }
    _listHead = NULL;

}

studentCollection::studentList studentCollection::copyStudentCollection(const studentList& original){
    if (original == NULL)
        return NULL;
    
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * newPtr = newList;
    studentNode * oldPtr = original->next;

    while (oldPtr != NULL){
        newPtr->next = new studentNode;
        newPtr = newPtr->next;
        newPtr->studentData = oldPtr->studentData;
        oldPtr = oldPtr->next;
    }
    newPtr->next = NULL;

    return newList;
}
studentCollection::~studentCollection(){
    std::cout<<"destructor called\n";
    deleteList(_listHead);
}

studentCollection& studentCollection::operator=(const studentCollection& rhs){
    
    if (this != &rhs){
        deleteList(_listHead);
        _listHead =  copyStudentCollection(rhs._listHead);
    }
        return *this; 
}

int main(){

// student collection inside brackets
{
    studentCollection sc;
    {
        studentRecord charles;
        charles.id = 1;
        charles.grade = 12;
        charles.name = "Charles";
        sc.addRecord(charles);

        studentRecord bobby(2,4,"Bobby");
        sc.addRecord(bobby);

        studentRecord tommy(3,7,"Tommy");
        sc.addRecord(tommy);

        studentRecord chuck(4,10,"Chuck");
        sc.addRecord(chuck);


        studentRecord will(5,12,"Will");
        sc.addRecord(will);
    }
    sc.printRecords();
    {
        studentRecord idTwoStudent = sc.recordWithNumber(2);
        studentRecord idOneStudent = sc.recordWithNumber(1);
        studentRecord idFourStudent = sc.recordWithNumber(4);
        //idOneStudent.printStudent();
        //idTwoStudent.printStudent();
        sc.removeRecord(idTwoStudent);
        sc.removeRecord(idFourStudent);
        sc.removeRecord(idOneStudent);

    }
    sc.printRecords();
}
// clean up memory
// 100.000 student nodes inside collection 
{
    studentCollection sc;
    for (size_t i = 0; i < 100000; i++){
        sc.addRecord(studentRecord(i,i,"timmy"));
    }
}
// clean up memory

// Deep-copy students instead of shallow copy
{
    studentCollection sc1;
    studentCollection sc2;

    studentRecord bobby(2,4,"Bobby");
    sc1.addRecord(bobby);
    studentRecord tommy(3,7,"Tommy");
    sc1.addRecord(tommy);

    studentRecord chuck(4,10,"Chuck");
    sc1.addRecord(chuck);

    sc2 = sc1;
    sc2.removeRecord(bobby);
    sc2.removeRecord(tommy);
    sc2.printRecords();

    sc1.removeRecord(chuck);
    sc1.removeRecord(tommy);
    sc1.printRecords();
}

}
