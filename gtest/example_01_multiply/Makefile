SRC= multiply.cpp multiply_test.cpp
OBJ= multiply.o multiply_test.o 

BIN := test

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ)
	g++ -Wall -Wextra $^ -o $@ -lgtest -pthread
$(OBJ):%.o:

%.o:%.cpp
	g++ -Wall -Wextra -c $^ -lgtest -pthread

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ)