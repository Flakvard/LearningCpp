#include <string>
#include <iostream>

class hashtable
{
private:
    int bucketSize;
    char hashTable[0];

public:
    hashtable();
    ~hashtable();
    int hashFunction(std::string index);
};

hashtable::hashtable()
{
}

hashtable::~hashtable()
{
}
int hashFunction(std::string index){
    return 0;
}

int main(){
    std::cout<<"Hello world\n";
    char* arr[10];
    hashtable ht;
}