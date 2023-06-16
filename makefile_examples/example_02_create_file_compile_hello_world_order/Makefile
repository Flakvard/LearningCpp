blah: blah.o 				#1. starts with blah, but looks for blah.o
	./blah.o				#5. executes the compiled blah file
blah.o: blah.cpp 			#2. find blah.o, but looks for blah.cpp
	g++ blah.cpp -o blah.o	#4 now blah.cpp is done, it can execute the compile command
blah.cpp:					#3. finds blah.cpp and echos hello world > blah.cpp 
	echo "#include <iostream>\nint main(){ std::cout<<\"Hello World\"<<std::endl; return 0;}" > blah.cpp #

clean:
	rm -f blah.cpp blah.o