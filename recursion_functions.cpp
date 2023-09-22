#include <iostream>

int recursiveSumArr(int setofnumbers[], int size){
    if (size == 0) return 0;
    int sum = setofnumbers[size-1];
    sum += recursiveSumArr(setofnumbers, size-1);
    return sum;
}

int main(){

    int setofnumbers[] = {1,3,6,2}; // 12
    int sum = 0;
    int count = 4;
    sum = recursiveSumArr(setofnumbers, count);

    std::cout<<sum<<'\n';
}