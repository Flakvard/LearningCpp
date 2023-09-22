#include <iostream>

int recursiveSumArr(int setofnumbers[], int size){
    if (size == 0) return 0;
    int sum = setofnumbers[size-1];
    sum += recursiveSumArr(setofnumbers, size-1);
    return sum;
}

double recursiveAvgArr(int setofnumbers[], int size){
    if (size == 0) return 0;
    int sum = 0;
    sum += recursiveAvgArr(setofnumbers, size-1);
    sum += setofnumbers[size-1];
    return sum;
}

double recursiveAvgCaller(int setofnumbers[], int size){
    double avg = 0;
    double sum = 0;
    sum = recursiveAvgArr(setofnumbers, size); 
    avg = sum/size;
    return avg;
}


int main(){

    int setofnumbers[] = {1,3,6,2,-4,-2,5,3}; // 14
    int count = 8;
    int sum = recursiveSumArr(setofnumbers, count); // 14
    double avg = recursiveAvgCaller(setofnumbers, count); // 3
    //double avg = avgArr(setofnumbers, count);

    std::cout<<sum<<'\n';
    std::cout<<avg<<'\n';
}