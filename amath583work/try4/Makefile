CXX	= c++
CXXFLAGS	= -Wall -g -std=c++11
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

Vector.o: Vector.cpp Vector.hpp
	@$(CXX) $(CXXFLAGS) -c Vector.cpp -o Vector.o

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -c Matrix.cpp -o Matrix.o

daltMatrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -DALTMATRIX -c Matrix.cpp -o daltMatrix.o

tryMatrix.o: tryMatrix.cpp
	@$(CXX) $(CXXOPTM) -c tryMatrix.cpp -o tryMatrix.o

tryVector.o: tryVector.cpp
	@$(CXX) $(CXXOPTM) -c tryVector.cpp -o tryVector.o

daltMatrix: daltMatrix.o tryMatrix.o
	@$(CXX) $(CXXOPTM) daltMatrix.o tryMatrix.o -o daltMatrix

tryMatrix: Matrix.o tryMatrix.o
	@$(CXX) $(CXXOPTM) Matrix.o tryMatrix.o -o tryMatrix

tryVector: Vector.o Matrix.o tryVector.o
	@$(CXX) $(CXXOPTM) Vector.o Matrix.o tryVector.o -o tryVector

clean:
	@/bin/rm -f fail success timing1 timing2 performance1 performance2 Vector.o daltMatrix.o Matrix.o tryMatrix.o tryVector.o tryMatrix daltMatrix tryVector
	@$ clear