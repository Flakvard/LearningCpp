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
    void printTable();
    int getBucketSize();
    int* gethashtable();

private:
    int bucketSize;
    int* hashTable;
};

void hashtable::testTable(){
    int size = getBucketSize();
    int* arr = gethashtable();
    for (int i = 0; i < size; i++){
        arr[i] = std::rand() % 100;
    }
}

int hashtable::getBucketSize(){
    return bucketSize;
}
int* hashtable::gethashtable(){
    return hashTable;
}

void hashtable::printTable(){
    int size = getBucketSize();
    int* arr = gethashtable();
    for (int i = 0; i < size; i++){
        std::cout<<arr[i]<<'\n';
    }
}

hashtable::hashtable()
{
    bucketSize = 10;
    hashTable = new int[bucketSize];
}

hashtable::~hashtable()
{
    // Nothing to do yet
}
int hashFunction(std::string index){
    return 0;
}

int main(){
    hashtable ht;
    ht.testTable();
    ht.printTable();

}