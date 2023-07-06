SRC = ./src/main.cpp ./src/factory.cpp ./src/employee.cpp ./src/developer.cpp ./src/teacher.cpp
OBJ = main.o factory.o employee.o developer.o teacher.o

BIN = ./build/tester
srcFolder := ./src/

buildFolder = ./build

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJ)
	g++ -o $@ $(OBJ) 

$(OBJ): $(SRC)
	g++ -Wall -Wextra -c $^


clean:
	rm -rf $(buildFolder)/*;
	rm *.o;