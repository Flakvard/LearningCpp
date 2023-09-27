#include <string>
#include <iostream>
#include <random>

class hashtable
{
public:
    hashtable();
    ~hashtable();
    int hashFunction(std::string index);
    void testTable();
    //void printTable();
    int getBucketSize();
    char* gethashtable();

private:
    int bucketSize = 10;
    char hashTable[10];
};

void hashtable::testTable(){
    int size = getBucketSize();
    char* arr = gethashtable();
    for (int i = 0; i < size; i++){
        arr[i] = std::rand() % 100;
    }

}

int  hashtable::getBucketSize(){
    return bucketSize;
}
char*  hashtable::gethashtable(){
    return hashTable;
}

hashtable::hashtable()
{
    // Nothing to do yet
}

hashtable::~hashtable()
{
    // Nothing to do yet
}
int hashFunction(std::string index){
    return 0;
}

int main(){
    char* arr[10];
    hashtable ht;
    ht.testTable();

}