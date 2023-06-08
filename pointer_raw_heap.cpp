#include <memory>
#include <iostream>

int main(){

    // important to deal with memory allocation in one place
    // when all the values get turned back and everything is done we can delete the allocation
    // the problem is when something goes bad and the pointer/address stops in the middle of a functin
    // and does not come back. Thats when we have memory leak. 
    //
    // int arr[1][3][3] = {
    //     {
    //         {1,1,1,},
    //         {2,2,2,},
    //         {3,3,3,}
    //     }
    // };

    // int arr[3] = {1,2,3,};
    // int* arr1[3] = &arr; 

}