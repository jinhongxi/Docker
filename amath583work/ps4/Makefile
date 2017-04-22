CXX	= c++
CXXG	= -Wall -g -std=c++11 -Wc++11-extensions
CXXO3	= -Wall -O3 -std=c++11 -Wc++11-extensions
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -Wall

fail: fail.cpp
	@$(CXX) $(CXXG) fail.cpp -o fail
	@$(CXX) $(CXXG) -DNDEBUG  fail.cpp -o success

timing: timing.cpp
	@$(CXX) $(CXXG) timing.cpp -o timing1
	@$(CXX) $(CXXO3) timing.cpp -o timing2

performance: performance.cpp
	@$(CXX) $(CXXG) performance.cpp -o performance1
	@$(CXX) $(CXXO3)  performance.cpp -o performance2

daltMatrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXG) -DALTMATRIX -c Matrix.cpp -o daltMatrix.o

tryMatrix.o: tryMatrix.cpp
	@$(CXX) $(CXXG) -c tryMatrix.cpp -o tryMatrix.o

tryVector.o: tryVector.cpp Matrix.hpp Vector.hpp
	@$(CXX) $(CXXO3) -c tryVector.cpp -o tryVector.o

amath583.o: amath583.cpp Matrix.hpp Vector.hpp
	@$(CXX) -O3 -std=c++11 -Wc++11-extensions -c amath583.cpp -o amath583.o

daltMatrix: daltMatrix.o tryMatrix.o
	@$(CXX) $(CXXG) daltMatrix.o tryMatrix.o -o daltMatrix

tryMatrix: Matrix.o tryMatrix.o
	@$(CXX) $(CXXO3) Matrix.o tryMatrix.o -o tryMatrix

try583: try583.cpp amath583.o Matrix.o Vector.o
	@$(CXX) $(CXXO3) try583.cpp amath583.o Matrix.o Vector.o -o try583

tryVector: tryVector.o Matrix.o Vector.o
	@$(CXX) $(CXXO3) Vector.o Matrix.o tryVector.o -o tryVector

bench: bench.o Matrix.o Vector.o
	$(CXX) $(CXXFLAGS) bench.o Matrix.o Vector.o -o bench

sparsebench: sparsebench.o COO.o
	$(CXX) $(CXXFLAGS) sparsebench.o COO.o -o sparsebench

bench.o: bench.cpp Matrix.hpp Vector.hpp
	$(CXX) $(CXXFLAGS) -c bench.cpp -o bench.o

sparsebench.o: sparsebench.cpp COO.hpp
	$(CXX) $(CXXFLAGS) -c sparsebench.cpp -o sparsebench.o

COO.o: COO.cpp COO.hpp
	$(CXX) $(CXXFLAGS) -Wall -c COO.cpp -o COO.o

Matrix.o: Matrix.cpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp
	$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

clean:
	/bin/rm -f bench bench.o Matrix.o Vector.o sparsebench sparsebench.o
	@/bin/rm -f fail success timing1 timing2 performance1 performance2 daltMatrix daltMatrix.o tryMatrix tryMatrix.o tryVector tryVector.o try583 amath583.o
