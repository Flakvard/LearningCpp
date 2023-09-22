#include <iostream>


int sumOfArr(int setofnumbers[], int size){
    int sum = 0;
    for (size_t i = 0; i < 4; i++){
        sum += setofnumbers[i];
    }
    return sum;
}

int dispacterSum(int setofnumbers[], int size){
    if (size == 0) return 0;
    int sum = setofnumbers[size-1];
    sum += dispacterSum(setofnumbers, size-1);
    return sum;
}

int main(){

    int setofnumbers[] = {1,3,6,2}; // 12
    int sum = 0;
    int count = 4;
    sum = dispacterSum(setofnumbers, count);

    std::cout<<sum<<'\n';
}