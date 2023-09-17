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
    printStr(word);
}


void appendStr(arrayString &str, char letter){

    // count str lenght
    // fx. test0 == 4 lenght
    int count = 0;
    while (str[count]!=0) 
        ++count;
    
    // increase string with the new letter + 1 for count
    // fx. test!0 == 4+2
    arrayString newStr = new char[count+2];

    // copy over old str to newStr and add letter
    // stops a letter 'count' which should be the NULL char
    // fx. test0 == 4 and stops at test == 3 
    for (int i = 0; i < count; i++) 
        newStr[i]=str[i];

    // append char to word
    // fx. count == 4
    // test == 3 
    // test! == 4 
    newStr[count]=letter;
    // append NUll char to word
    // fx. count+1 == 5
    // test! == 4 
    // test!0 == 5 
    newStr[count+1]=0;

    // delete old str in heap, but not the pointer
    delete[] str;
    // assign the old pointer to the new word in heap
    str = newStr;
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