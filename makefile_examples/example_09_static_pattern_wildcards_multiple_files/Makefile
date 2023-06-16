objects := foo.o bar.o all.o

all: $(objects)

# to silence all outputsobjects target depends on all the *.o files and all the *.o depend on all the *.c files
# this also compiles all the *.c files into *.o files after all the *.c targets have been executed
$(objects): %.o : %.c

all.c:
	echo "int main(){ return 0;}" > all.c # if we dont do this then a file called all.c.c will be created

%.c: # 1. create all the *.c files
	touch $@

%.c: # 2. echo inside all the *.c files the main 
	echo "int main(){ return 0;}" > $@

clean:
	rm *.c *.o