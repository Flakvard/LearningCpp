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

    int i = 0;
    while (word[i]!=0)
    {
        std::cout<<word[i];
        ++i;
    }
    
    std::cout<<"\nword count: "<<i<<'\n';
    delete[] word;
    std::cout<<"word deleted\n";
       // append to string



}