#include <cassert>
#include <iostream>
#include <string>
#include <cstring>

void print(std::string name);
void printChar(char name[]);

int main(){
    std::string bob = "Bob";
    print(bob);

    char bobby[] = "Bob";
    printChar(bobby);

}

void print(std::string name){
    assert(name == "Bob");
    std::cout<<"The name is "<<name<<'\n';
}
void printChar(char name[]){
    assert(strcmp(name, "Bob") == 0);
    std::cout<<"The name is "<<name<<'\n';
}