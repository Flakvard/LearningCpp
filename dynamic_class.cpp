#include <iostream>

struct studentRecord{
    int id = 0;
    int grade = 0;
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
    addRecord();
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

studentCollection::addRecord()
{
}

studentRecord studentCollection::recordWithNumber(int idNum)
{
    //return studentRecord();
}

studentCollection::~studentCollection()
{
}


int main(){



}
