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

    int num1 = 10;

    // an pointer to an array of integers
    int* arr_pointer = new int[10]; // allocates 1 addresse to 10*4 = 40 bytes of memory (integers) and we can store any type inside
    arr_pointer[0] = num1; // integers
    int n = sizeof(arr_pointer)/sizeof(arr_pointer[0]);

    // This arr_pointer_to_pointers is the same as arr_pointer 
    // an pointer to an array of integers pointers
    int** arr_pointer_to_pointers = new int*[10]; // same as arr_pointer - allocates 40 bytes of memory
    arr_pointer_to_pointers[0] = nullptr; // integers pointers
    for(int i = 0; i<10; i++)
        arr_pointer_to_pointers[i] = new int[20];


    int** arr2D = new int*[10];
    for(int i = 0; i < 10; i++)
        arr2D[i] = new int[10];


    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++i)
            arr2D[i][j] = 0+j+i;
    }
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++i)
            std::cout<<arr2D[i][j];
    }

    // int* arrVals = new int[3]{1,2,3};

    // int* arr2d[5]{new int[20]}; // allocates 5 addresses to 20*4 = 80 different bytes of memory. Which means 5*80 = 400 bytes of memmory allocated.


    /// 3D array multi dimension

    int*** arr3D = new int**[50];
    for(int i = 0; i < 50; ++i){
        arr3D[i] = new int*[50];
        for(int j = 0; j < 50; ++j){
            int** ptr = arr3D[i];
            ptr[j] = new int[50];
        }
    }

    arr3D[0][0][0] = int(0);
    arr3D[0][0][1] = int(0);
    arr3D[0][0][2] = int(0);
    arr3D[0][0][3] = int(0);



    // int arr[3] = {1,2,3,};
    // int* arr1[3] = &arr; 
    std::cin.get();

}