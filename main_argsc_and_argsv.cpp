#include <iostream>
/*
What does this mean?
int main(int argc, char *argv[]){
     … 
}
- int before main indicates that the function returns an integer value.
  The return value of main is used to indicate the program's execution status or result.
  By convention, a return value of 0 usually indicates successful execution, while a non-zero value indicates an error or abnormal termination.
- int argc stands for "argument count" and represents the number of command-line arguments passed to the program when it is executed.
- char *argv[] stands for "argument vector" and represents an array of strings containing the command-line arguments themselves.
The values of argc and argv are automatically provided by the runtime system when the program starts.
The first command-line argument (argv[0]) typically contains the name or path of the program being executed.
Here's an example to illustrate how the argc and argv parameters are used:

*/
int main(int argc, char *argv[]) { // can also use `char const* argv[]` to pass immutable arguments/inputs (READ-ONLY in main to avoid unintentional modifications)
    // Print the total number of command-line arguments
    std::cout << "Number of arguments: " << argc << std::endl;

    // Print each command-line argument
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
/*
// running the program without inputs
PS C:\xampp\htdocs\LearningCpp> .\main_argsc_and_argsv.exe
Number of arguments: 1
Argument 0: C:\xampp\htdocs\LearningCpp\main_argsc_and_argsv.exe

// running the program with inputs
PS C:\xampp\htdocs\LearningCpp> .\main_argsc_and_argsv.exe arg1 arg2 arg3
Number of arguments: 4
Argument 0: C:\xampp\htdocs\LearningCpp\main_argsc_and_argsv.exe
Argument 1: arg1
Argument 2: arg2
Argument 3: arg3
PS C:\xampp\htdocs\LearningCpp>

*/

