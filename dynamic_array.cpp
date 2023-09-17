#include <iostream>
#include <assert.h>

typedef char* arrayString;

void printStr(const arrayString &str);
void appendStr(arrayString &str, char letter);

int main(){

    std::cout<<"Hello word\n";


    arrayString word = new char[5];

    word[0]='t'; 
    word[1]='e'; 
    word[2]='s'; 
    word[3]='t'; 
    word[4]=0; 
    printStr(word);
    
    // delete[] word;
    // std::cout<<"word deleted\n";

    // assert( (2+2==4) && "expect");
    // std::cout<<"assert done\n";
    appendStr(word, '!');
}


void appendStr(arrayString &str, char letter){

    // count str lenght
    int count = 0;
    while (str[count]!=0) ++count;
    
    // increase string with the new letter + 1 for count
    arrayString newStr = new char[count+2];

    // copy over old str to newStr and add letter
    for (int i = 0; i < count; i++)
    {
        newStr[i]=str[i];
    }
    newStr[count+1]=letter;
    newStr[count+2]=0;
    printStr(newStr);
    delete[] newStr;
}

void printStr(const arrayString &str){
    int i = 0;
    while (str[i] != 0)
    {
        std::cout<<str[i];
        ++i;
    }
    std::cout<<'\n';
    
}