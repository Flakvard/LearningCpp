files := file1 file2 #2. files depends on file1 and file2

some_file: $(files) #1. first target and it depends on the variables files.
	echo "Look at this variable "$(files) #5. now both files are created, so it echos the varibles
	touch some_file # creates a new file called some_file

file1: #3. finds file1 and creates file1 
	touch file1

file2: #4. finds file1 and creates file1 
	touch file2

clean:
	rm file1 file2 some_file