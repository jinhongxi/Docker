hello: hello.cpp
	@c++ hello.cpp -o hello

goodbye: goodbye.cpp
	@c++ goodbye.cpp -o goodbye

test1: hello goodbye
	@echo "say hello then goodbye"
	@./hello
	@./goodbye
	@echo "done"

test2: hello goodbye
	@echo "say goodbye then hello"
	@./goodbye
	@./hello
	@echo "done"

assert1: hello1.cpp
	@c++ hello1.cpp -o hello1
	@./hello1

assert2: hello2.cpp
	@c++ hello2.cpp -o hello2
	@./hello2

assert3: hello3.cpp
	@c++ hello3.cpp -o hello3
	@./hello3

main.exe: main.o amath583.o
	c++ -g main.o amath583.o -o main.exe

main.o: main.cpp amath583.hpp
	c++ -g -std=c++11 -Wall -c main.cpp -o main.o

amath583.o: amath583.cpp amath583.hpp
	c++ -g std=c++11 -Wall -c amath583.cpp -o amath583.o
