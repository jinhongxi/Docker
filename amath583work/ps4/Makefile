CXX	= c++
CXXFLAGS	= -Wall -g -std=c++11 -Wc++11-extensions
CXXOPTM	= -Wall -O3 -std=c++11 -Wc++11-extensions

fail: fail.cpp
	@$(CXX) $(CXXFLAGS) fail.cpp -o fail

success: fail.cpp
	@$(CXX) $(CXXFLAGS) -DNDEBUG  fail.cpp -o success

timing1: timing.cpp
	@$(CXX) $(CXXFLAGS) timing.cpp -o timing1

timing2: timing.cpp
	@$(CXX) $(CXXOPTM) timing.cpp -o timing2

performance1: performance.cpp
	@$(CXX) $(CXXFLAGS) performance.cpp -o performance1

performance2: performance.cpp
	@$(CXX) $(CXXOPTM)  performance.cpp -o performance2

daltMatrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -DALTMATRIX -c Matrix.cpp -o daltMatrix.o

tryMatrix.o: tryMatrix.cpp
	@$(CXX) $(CXXFLAGS) -c tryMatrix.cpp -o tryMatrix.o

tryVector.o: tryVector.cpp Matrix.hpp Vector.hpp
	@$(CXX) $(CXXOPTM) -c tryVector.cpp -o tryVector.o

amath583.o: amath583.cpp Matrix.hpp Vector.hpp
	@$(CXX) -O3 -std=c++11 -Wc++11-extensions -c amath583.cpp -o amath583.o

daltMatrix: daltMatrix.o tryMatrix.o
	@$(CXX) $(CXXFLAGS) daltMatrix.o tryMatrix.o -o daltMatrix

tryMatrix: Matrix.o tryMatrix.o
	@$(CXX) $(CXXOPTM) Matrix.o tryMatrix.o -o tryMatrix

try583: try583.cpp amath583.o Matrix.o Vector.o
	@$(CXX) $(CXXOPTM) try583.cpp amath583.o Matrix.o Vector.o -o try583

tryVector: tryVector.o Matrix.o Vector.o
	@$(CXX) $(CXXOPTM) Vector.o Matrix.o tryVector.o -o tryVector

bench: bench.o Matrix.o Vector.o
	c++ -O3 -std=c++11 -Wc++11-extensions bench.o Matrix.o Vector.o -o bench

bench.o: bench.cpp Matrix.hpp Vector.hpp
	c++ -O3 -std=c++11 -Wc++11-extensions -c bench.cpp -o bench.o

Matrix.o: Matrix.cpp Matrix.hpp
	c++ -O3 -std=c++11 -Wc++11-extensions -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp
	c++ -O3 -std=c++11 -Wc++11-extensions -Wall -c Vector.cpp -o Vector.o

clean:
	/bin/rm -f bench bench.o Matrix.o Vector.o 
	@/bin/rm -f fail success timing1 timing2 performance1 performance2 daltMatrix.o tryMatrix.o tryVector.o tryMatrix daltMatrix tryVector try583 amath583.o
