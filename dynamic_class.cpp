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
    void removeRecord();
    void printRecords();
    ~studentCollection();
private:
    typedef studentNode * studentList;
    studentList _listHead;
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

void studentCollection::removeRecord()
{
}

void studentCollection::printRecords(){
    studentNode * loopPtr = _listHead;
    while (loopPtr->next != NULL){
        std::cout<<"ID: "
                 <<loopPtr->studentData.id
                 <<"\nName: "
                 <<loopPtr->studentData.name
                 <<"\nGrade: "
                 <<loopPtr->studentData.grade
                 <<'\n';
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL){
        return;
    }else{
        std::cout<<"ID: "
                 <<loopPtr->studentData.id
                 <<"\nName: "
                 <<loopPtr->studentData.name
                 <<"\nGrade: "
                 <<loopPtr->studentData.grade
                 <<'\n';
    }
    
}

studentCollection::~studentCollection()
{
}


int main(){

    studentCollection sc;
    {
        studentRecord charles;
        charles.id = 1;
        charles.grade = 12;
        charles.name = "Charles";
        sc.addRecord(charles);
    }
    sc.printRecords();
    {
        studentRecord bobby(2,4,"Bobby");
        sc.addRecord(bobby);
    }
    {
        studentRecord tommy(3,7,"Tommy");
        sc.addRecord(tommy);
    }
    sc.printRecords();

    studentRecord idTwoStudent = sc.recordWithNumber(2);
    studentRecord idOneStudent = sc.recordWithNumber(1);
    idOneStudent.printStudent();
    idTwoStudent.printStudent();


}
