CXX = g++ # Flag for implicit rules
CXXFLAGS = -g # Flag for implicit rules. Turn on debug info

# Implicit rule #1: blah is built via the C linker implicit rule
# Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
blah: blah.o

blah.cpp:
	echo "int main() { return 0; }" > blah.cpp

clean:
	rm -f blah*