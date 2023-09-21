#include <iostream>
#include <string>

struct studentRecord{
    int id = 0;
    int grade = 0;
    std::string name = "";
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

studentCollection::~studentCollection()
{
}


int main(){

    studentCollection sc;
    studentRecord charles;
    charles.id = 1;
    charles.grade = 12;
    charles.name = "Charles";
    sc.addRecord(charles);



}
