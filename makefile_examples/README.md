From https://makefiletutorial.com/

# Here's a list of implicit rules:

## Compiling a C program:
n.o is made automatically from n.c with a command of the form `$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
CC: Program for compiling C programs; default cc
CFLAGS: Extra flags to give to the C compiler

## Compiling a C++ program: 
n.o is made automatically from n.cc or n.cpp with a command of the form `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
CXX: Program for compiling C++ programs; default g++
CXXFLAGS: Extra flags to give to the C++ compiler

## Linking a single object file: 
n is made automatically from n.o by running the command `$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

## The important variables used by implicit rules are:
CPPFLAGS: Extra flags to give to the C preprocessor
LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker