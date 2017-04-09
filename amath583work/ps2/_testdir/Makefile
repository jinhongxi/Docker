hello: hello.cpp
	@c++ hello.cpp -o hello
	@./hello

goodbye: goodbye.cpp
	@c++ goodbye.cpp -o goodbye
	@./goodbye

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

amath583.o: amath583.cpp
	@c++ -c amath583.cpp -o amath583.o

seq: seq.cpp
	@c++ seq.cpp -o seq

readVector: readVector.cpp amath583.o
	@c++ readVector.cpp amath583.o -o readVector

genRandomVector: genRandomVector.cpp amath583.o
	@c++ genRandomVector.cpp amath583.o -o genRandomVector

vectorNorm: vectorNorm.cpp amath583.o
	@c++ vectorNorm.cpp amath583.o -o vectorNorm

dot583: dot583.cpp amath583.o
	@c++ dot583.cpp amath583.o -o dot583

package: seq.cpp amath583.cpp amath583.hpp readVector.cpp genRandomVector.cpp vectorNorm.cpp dot583.cpp ex2.txt ref2.txt Makefile
	@tar -czf ps2.tgz seq.cpp amath583.cpp amath583.hpp readVector.cpp genRandomVector.cpp vectorNorm.cpp dot583.cpp ex2.txt ref2.txt Makefile

tests583:
	python test_ps2.py True