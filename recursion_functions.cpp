#include <iostream>


int sumOfArr(int setofnumbers[], int size){
    int sum = 0;
    for (size_t i = 0; i < 4; i++){
        sum += setofnumbers[i];
    }
    return sum;
}

int main(){

    int setofnumbers[] = {1,3,6,2}; // 12
    int sum = 0;
    int count = 4;
    sum = sumOfArr(setofnumbers, count);

    std::cout<<sum<<'\n';
}