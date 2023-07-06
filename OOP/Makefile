SRC = ./src/main.cpp ./src/factory.cpp ./src/employee.cpp ./src/developer.cpp ./src/teacher.cpp
OBJ = ./build/main.o ./build/factory.o ./build/employee.o ./build/developer.o ./build/teacher.o

BIN = ./build/tester

buildFolder = ./build

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJ)
	g++ -Wall -Wextra $(OBJ) -o $(BIN)

$(OBJ): $(SRC)
	g++ -Wall -Wextra -c $(SRC) 
	mv *.o $(buildFolder)

clean:
	rm -rf $(buildFolder)/*