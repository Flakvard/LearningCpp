#include <string>
#include <iostream>
#include <random>

template <typename T> 
class hashtable {
public:
    hashtable();
    ~hashtable();
    int hashFunction(T index);
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
    testHTint();

}
void testHTstr(){

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
    bucketSize = 10;
    hashTable = new T[bucketSize];
}

template <typename T> 
hashtable<T>::~hashtable()
{
    // Nothing to do yet
}
template <typename T> 
int hashtable<T>::hashFunction(T value){
    int sizeofTable = getBucketSize();
    int index = value % sizeofTable;
    return index;
}

template <typename T>
void hashtable<T>::append(T num){
    int index = hashFunction(num);
    T* table = gethashtable();
    table[index] = num;
}