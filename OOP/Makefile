SRC = ./src/main.cpp ./src/factory.cpp ./src/employee.cpp ./src/developer.cpp ./src/teacher.cpp
OBJ = $(patsubst ./src/%.cpp, ./build/%.o, $(SRC))

BIN = $(buildFolder)/tester

srcFolder := ./src/

buildFolder = ./build

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJ)
	g++ -o $@ $(OBJ) 

./build/%.o: ./src/%.cpp
	@mkdir -p $(@D)
	g++ -Wall -Wextra -c -o $@ $<


clean:
	rm -rf $(buildFolder)/*;
	rm *.o;