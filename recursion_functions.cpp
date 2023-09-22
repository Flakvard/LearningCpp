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

int recursivePositivSum(int setofnumbers[], int size){
    if (size == 0) 
        return 0;
    int positivSum = 0;
    if (setofnumbers[size-1] >= 0) 
        positivSum = setofnumbers[size-1]; 
    positivSum += recursivePositivSum(setofnumbers, size-1);
    return positivSum;
}

int main(){

    int setofnumbers[] = {1,3,6,2,-4,-2,5,3}; // 14.0
    int size = 8;
    int sum = recursiveSumArr(setofnumbers, size); // 14.0
    double avg = recursiveAvgCaller(setofnumbers, size); // 1.75
    int posSum = recursivePositivSum(setofnumbers, size); // 20.0
    //double avg = avgArr(setofnumbers, count);

    std::cout<<sum<<'\n';
    std::cout<<avg<<'\n';
    std::cout<<posSum<<'\n';
}