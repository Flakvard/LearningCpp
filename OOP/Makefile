SRC = main.cpp factory.cpp employee.cpp developer.cpp teacher.cpp builder.cpp director.cpp
OBJ = $(patsubst %.cpp, $(buildFolder)/%.o, $(SRC))

BIN = $(buildFolder)/tester
srcFolder := ./src/
headerFolder := ./lib/

buildFolder = ./build

VPATH = $(srcFolder)

CPPFLAGS = -MMD -MP -I$(headerFolder)
CXXFLAGS = -Wall -Wextra

.PHONY: all clean
all: $(BIN)
	@echo

$(BIN): $(OBJ)
	g++ -o $@ $(OBJ)

-include $(OBJ:.o=.d)

$(buildFolder)/%.o: %.cpp
	@mkdir -p $(@D)
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rfv $(buildFolder)/*