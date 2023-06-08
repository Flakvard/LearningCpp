#include <iostream>


int main(){
    int* ptr = new int[10];

    for(int i = 0; i < 10; i++){
        ptr[i] = 10+i;
    }
    for(int i = 0; i < 10; i++){
        std::cout<<ptr[i]<<" ";
    }


    std::cin.get();
}