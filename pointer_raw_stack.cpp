#include <memory>
#include <iostream>


void fooIncrementer(int &num1);

int main(){

    // A pointer is always a int
    // it is just a address of a variable
    int num1 = 10;
    int num2 = 99;
   // num2 = &num1; // this wont work: You cannot assaign the address of num1 to a int num2 (int* num2 needs to be a pointer)
   int* ptr_to_num2 = &num2;

{ // Scope inside main()
    // int* ptr_to_num1 = num1; // this wont work: You need address address of num1 by using reference '&'.
    int* ptr_to_num1 = &num1;
    int* ptr_to_ptr = ptr_to_num1; // pointer to a pointer
    *ptr_to_ptr = 20; // changes num1 to 20
} // both pointers get deleted
    // ptr_to_num1 = -10; // this wont work: You need to dereference the pointer to access the value inside.
    // *ptr_to_ptr = -10; // this wont work: Pointer gets deleted in the scope

    fooIncrementer(num1); // Pass-by-reference (only the address) and increments num1 by 1; 
    std::cin.get();
}

void fooIncrementer(int &num1){ // pass by reference (not a copy of num1, but the actual values of num1) - can use pointers now
    int number = 0;
    int* ptr = &num1; // This works only if it is pass-by-reference (int &num1)
    number = num1; // This always works
    *ptr = 30; // IMPORTANT num1 gets changed to 30
    number = 199; // IMPORTANT num1 does NOT get changed to 99
    // int* ptr_to_outofscope_num2 = &num2; // num2 is not declared. Can only access inside scope.
    // int* ptr_to_outofscope_num2 = ptr_to_num2; // ptr_to_num2 is not declared. Can only access inside scope.
}// pointer gets deleted
