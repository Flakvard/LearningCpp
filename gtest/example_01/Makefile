SRC= multiply.cpp multiply_test.cpp
OBJ= multiply.o multiply_test.o 

BIN := test

#all:$(BIN)

#$(BIN):$(OBJ)
#	#g++ -o $@ $^

#%.o:%.cpp
#	#g++ -Wall -Wextra -l gtest -o $^ multiply.h

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ)
	g++ -o $@ $^

%.o:%.cpp
	g++ -Wall -Wextra -l gtest -o $^ multiply.h

.PHONY: clean
#clean:
#	rm -rf $(BIN) $(OBJ)