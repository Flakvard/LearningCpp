#include <string>
#include <iostream>
#include <random>

class hashtable
{
public:
    hashtable();
    ~hashtable();
    int hashFunction(int index);
    void testTable();
    void printTable();
    int getBucketSize();
    int* gethashtable();
    void append(int num);

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
int hashtable::hashFunction(int index){
    int sizeofTable = getBucketSize();
    int indexAt = index % sizeofTable;
    return indexAt;
}

void hashtable::append(int num){
    int index = hashFunction(num);
    int* table = gethashtable();
    table[index] = num;
}

int main(){
    hashtable ht;
    ht.testTable();
    ht.printTable();
    ht.append(0);
    ht.append(1);
    ht.append(2);
    ht.append(3);
    ht.append(4);
    ht.append(5);
    ht.append(6);
    ht.append(7);
    ht.append(8);
    ht.append(9);
    ht.append(10);
    std::cout<<'\n';
    ht.printTable();

}