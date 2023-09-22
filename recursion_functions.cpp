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
int recursiveCountNum(int setofnumbers[], int size, int num){
    if (size == 0) 
        return 0;
    int count = 0;
    count += recursiveCountNum(setofnumbers, size-1, 3);
    if (setofnumbers[size-1] == num)
        ++count;
    return count;
}

int main(){

    int setofnumbers[] = {3,-1,3,6,2,-4,-2,5,3,3}; 
    int size = sizeof(setofnumbers)/sizeof(setofnumbers[0]);
    int sum = recursiveSumArr(setofnumbers, size); // 18
    double avg = recursiveAvgCaller(setofnumbers, size); // 1.8
    int posSum = recursivePositivSum(setofnumbers, size); // 25
    int count = recursiveCountNum(setofnumbers, size, 3); // 4
    //double avg = avgArr(setofnumbers, count);

}