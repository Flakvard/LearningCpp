# this example it first looks for other file,j
some_file: other_file
	echo "This file will always run and always second"
	touch other_file # this is redundant, but it creates other_file

other_file:
	echo "This file will always run and always first"

clean:
	rm -f other_file