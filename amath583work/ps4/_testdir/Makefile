CXX	= c++
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -Wall

bench: bench.o Matrix.o Vector.o
	$(CXX) $(CXXFLAGS) bench.o Matrix.o Vector.o -o bench

sparsebench: sparsebench.o COO.o Vector.o
	$(CXX) $(CXXFLAGS) sparsebench.o COO.o Vector.o -o sparsebench

bench.o: bench.cpp Matrix.hpp Vector.hpp
	$(CXX) $(CXXFLAGS) -c bench.cpp -o bench.o

sparsebench.o: sparsebench.cpp COO.hpp
	$(CXX) $(CXXFLAGS) -c sparsebench.cpp -o sparsebench.o

COO.o: COO.cpp COO.hpp
	$(CXX) $(CXXFLAGS) -Wall -c COO.cpp -o COO.o

Matrix.o: Matrix.cpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

clean:
	/bin/rm -f bench bench.o Matrix.o Vector.o sparsebench sparsebench.o COO.o

package: amath583.cpp bench.cpp COO.cpp COO.hpp ex4.txt Makefile Matrix.cpp Matrix.hpp ps4bex1.cpp ps4bex2.cpp ps4ex3.txt ps4exec.txt sparsebench.cpp Timer.hpp Vector.cpp Vector.hpp
	@$ tar -czf ps4.tgz amath583.cpp bench.cpp COO.cpp COO.hpp ex4.txt Makefile Matrix.cpp Matrix.hpp ps4bex1.cpp ps4bex2.cpp ps4ex3.txt ps4exec.txt sparsebench.cpp Timer.hpp Vector.cpp Vector.hpp

tests583:
	python test_ps4.py True
