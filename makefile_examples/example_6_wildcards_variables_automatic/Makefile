thing_wrong := *.o # dont do this, *.cpp will not get expanded
thing_right := $(wildcard *.o) # this is correct

# dependes on all four targets
all: one two three four

# Fails to find the file "*.o" and creates a new file called "*.o" instead
# make automatically tries to compile it aswell
one: $(thing_wrong)

# acts just like 'one' it failes to find the file "*.o" and creates it instead
two: *.o

# finds three.cpp and compiles it into three.o
three: $(thing_right)

# acts the same as three, but finds four.cpp and compiles to four
four: $(wildcard *.o) # same as three

clean:
	rm four three two one "*.o"