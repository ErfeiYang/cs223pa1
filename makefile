# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o data.o player.o
	g++ main.o data.o player.o -o PA1

main.o: main.cpp data.hpp player.hpp
	g++ -c main.cpp 

data.o: data.cpp data.hpp
	g++ -c data.cpp 

player.o: player.cpp player.hpp
	g++ -c  play.cpp

clean: 
	-rm *.o

run:
	@./PA1