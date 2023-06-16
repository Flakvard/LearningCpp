obj_files := foo.result bar.o lose.o
src_files := foo.raw bar.c lose.c

all: $(obj_files) #1. starts here and depends on obj_files 
.PHONY: all # important to add because otherwise it will do a implicit build/compile on 'all.o', 'all.c' and other 'all' files

$(filter %.o, $(obj_files)): %.o : %.c # filter all *.o files inside varibale obj_files and it depends on first *.o files then *.c files to execute first
	echo "target: $@ prereq $<" # echo the name of target file $@ and their prereq $<

$(filter %.result, $(obj_files)): %.result : %.raw # Same as above but for *.raw and *.result files
	echo "target: $@ prereq $<" # same as above

%.c %.raw: # two different targes, all *.c files and *.raw files get created
	touch $@ 

clean:
	rm $(src_files)