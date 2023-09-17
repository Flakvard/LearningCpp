#include <iostream>





int main(){

    std::cout<<"Hello word\n";

    typedef char* arrayString;

    arrayString word = new char[5];

    word[0]='t'; 
    word[1]='e'; 
    word[2]='s'; 
    word[3]='t'; 
    word[4]=0; 

    for (size_t i = 0; i < 5; i++)
    {
        std::cout<<word[i];
    }
    std::cout<<"\nend\n";
    delete[] word;
    std::cout<<"word deleted\n";
       // append to string



}