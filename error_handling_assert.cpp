#include <cassert>
#include <iostream>
#include <string>

void print(std::string name);

int main(){
    std::string bob = "Tom";
    print(bob);

}

void print(std::string name){
    assert(name == "Bob");
    std::cout<<"The name is "<<name<<'\n';
}