# create a command string for makefile
# hello:
# 	echo $(cooly)
# we use two $ because we do not want to pass the string variable "The ... me!" , just the "$(cooly)"
new_contents = "hello:\n\techo \$$(cooly)"

all:
	mkdir -p subdir
	printf $(new_contents) | sed -e 's/^ //' > subdir/Makefile
	@echo "--------MAKEFILE CONTENTS---------"
	@cd ./subdir && cat Makefile
	@echo "\n------END MAKEFILE CONTENTS-------"
	cd ./subdir && $(MAKE)

cooly = "The subdirectory can see me!"
export cooly

clean:
	rm -rf subdir