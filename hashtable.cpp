#include <string>
#include <iostream>
#include <random>

template <typename T> 
class hashtable {
public:
    hashtable();
    ~hashtable();
    int hashFunction(int index);
    int hashFunction(std::string index);
    void testTable();
    void printTable();
    int getBucketSize();
    T* gethashtable();
    void append(T num);

private:
    int bucketSize;
    T* hashTable;
};

void testHTint();
void testHTstr();

int main(){
    hashtable<int> ht;
    testHTstr();

}
void testHTstr(){
    hashtable<std::string> ht;
    ht.append("Hello");    ht.append("my");    ht.append("friend");    ht.append("it is good day,");    ht.append("amirite?");    ht.append("Yes,");    ht.append("very good!");
    std::cout<<'\n';
    ht.printTable();
}

void testHTint(){
    hashtable<int> ht;
    ht.testTable();
    ht.printTable();
    ht.append(0);    ht.append(1);    ht.append(2);    ht.append(3);    ht.append(4);    ht.append(5);    ht.append(6);    ht.append(7);    ht.append(8);    ht.append(9);    ht.append(10);   
    std::cout<<'\n';
    ht.printTable();
}


template <typename T> 
void hashtable<T>::testTable(){
    int size = getBucketSize();
    T* arr = gethashtable();
    for (int i = 0; i < size; i++){
        arr[i] = std::rand() % 100;
    }
}

template <typename T> 
int hashtable<T>::getBucketSize(){
    return bucketSize;
}
template <typename T> 
T* hashtable<T>::gethashtable(){
    return hashTable;
}

template <typename T> 
void hashtable<T>::printTable(){
    int size = getBucketSize();
    T* arr = gethashtable();
    for (int i = 0; i < size; i++){
        std::cout<<arr[i]<<'\n';
    }
}

template <typename T> 
hashtable<T>::hashtable()
{
    bucketSize = 55;
    hashTable = new T[bucketSize];
}

template <typename T> 
hashtable<T>::~hashtable()
{
    // Nothing to do yet
}
template <typename T> 
int hashtable<T>::hashFunction(int value){
    int sizeofTable = getBucketSize();
    int index = value % sizeofTable;
    return index;
}
template <typename T> 
int hashtable<T>::hashFunction(std::string value){
    int sizeofTable = getBucketSize();
    int count = value.length();
    int val = 0;
    for (int i = 0; i < count; i++)
    {
        val += static_cast<int>(value[i]);
    }
    
    int index = val % sizeofTable;
    return index;
}

template <typename T>
void hashtable<T>::append(T num){
    int index = hashFunction(num);
    T* table = gethashtable();
    table[index] = num;
}