#include <iostream>
#include <assert.h>

typedef char* arrayString;

void printStr(const arrayString &str);
void appendStr(arrayString &str, char letter);
arrayString catStr(arrayString s1, arrayString s2);
int lenghtStr(arrayString s);
arrayString subString(const arrayString str, int startPos, int endPos);

int main(){

    std::cout<<"Hello word\n";


    arrayString word = new char[5];

    word[0]='t';word[1]='e';word[2]='s';word[3]='t';word[4]=0; 
    printStr(word);
    appendStr(word, '!');
    printStr(word);

    // passing null values
    arrayString james = new char[0];
    // james has to have a 0 in the end of the text, otherwise it wont work
    james[0]=0;
    appendStr(james, 'j');appendStr(james, 'a');appendStr(james, 'm');appendStr(james, 'e');appendStr(james, 's');
    printStr(james);

    // appending with for loop from char array 
    arrayString darkness = new char[1];
    darkness[0]=0;
    // darkness[28]
    char hello[] = "hello darkness my old friend";
    for (size_t i = 0; i < 28; i++){
        appendStr(darkness,hello[i]);
    }
    printStr(darkness);
    arrayString jam_dark = catStr(james, darkness);
    arrayString jam_dark_rev = catStr(darkness, james);

    printStr(jam_dark);
    printStr(jam_dark_rev);

    // Testing subString funciton
    arrayString abcdefg = new char[1];
    abcdefg[0]=0;
    char testing[] = "abcdefg";
    for (size_t i = 0; i < 7; i++){
        appendStr(abcdefg,testing[i]);
    }
    printStr(abcdefg);
    arrayString cdef = subString(abcdefg,3,4);
    printStr(cdef);
    // arrayString hello = subString(darkness, 1,6); // "hello "
    // arrayString oldFriend = subString(darkness, 9,28); // " my old friend"
    // arrayString helloJames = catStr(hello, james);
    // arrayString fullSentance = catStr(helloJames, oldFriend);

    // cleanup memory allocation;
    {
    delete[] word;
    delete[] james;
    delete[] darkness;
    delete[] jam_dark;
    delete[] jam_dark_rev;
    }

    // cleanup dangling reference;
    {
    word = 0;
    james = 0;
    darkness = 0;
    jam_dark = 0;
    jam_dark_rev = 0;
    }

}

arrayString subString(const arrayString str, int startPos, int endPos){
    int count = 0;
    count = lenghtStr(str);
    // create a substring that is large enough to fit start to finish
    arrayString subStr = new char[startPos+endPos-1];
    for (int i = 0; i < endPos; i++){
        // starPos - 1 because it starts at 0 
        subStr[i] = str[startPos-1+i];
    }
    return subStr;
}

int lenghtStr(arrayString s){
    int count = 0;
    while (s[count] != 0){
        ++count;
    }
    return count;
}

arrayString catStr(arrayString s1, arrayString s2){
    // lenght of first str
    int count_s1 = 0;
    count_s1 = lenghtStr(s1);

    // lenght of second str
    int count_s2 = 0;
    count_s2 = lenghtStr(s2);

    // allocate length of both str
    arrayString strCat = new char[count_s1+count_s2];
    // insert first str
    for (int i = 0; i < count_s1; i++)
    {
        strCat[i] = s1[i];
    }
    // insert second str (start from lenght of first str)
    for (int i = 0; i < count_s2; i++)
    {
        strCat[count_s1+i] = s2[i];
    }
    // return
    return strCat;

}


void appendStr(arrayString &str, char letter){

    // count str lenght
    // fx. test0 == 4 lenght
    int count = 0;
    count = lenghtStr(str);
    
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