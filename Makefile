CXX	= c++
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -Wall

COO.o: COO.cpp COO.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c COO.cpp -o COO.o

AOSCOO.o: AOSMatrix.cpp AOSMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c AOSMatrix.cpp -o AOSCOO.o

CSCMatrix.o: CSCMatrix.cpp CSCMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c CSCMatrix.cpp -o CSCMatrix.o

CSRMatrix.o: CSRMatrix.cpp CSRMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c CSRMatrix.cpp -o CSRMatrix.o

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

amath583.o: amath583.cpp amath583.hpp Vector.hpp Matrix.hpp Timer.hpp COO.hpp AOSMatrix.hpp CSCMatrix.hpp CSRMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c amath583.cpp -o amath583.o

matvec.o: matvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c matvec.cpp -o matvec.o

matvec: matvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o
	@$(CXX) $(CXXFLAGS) matvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o -o matvec
 
aosmatvec.o: aosmatvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c aosmatvec.cpp -o aosmatvec.o

aosmatvec: aosmatvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o
	@$(CXX) $(CXXFLAGS) aosmatvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o -o aosmatvec

cscmatvec.o: cscmatvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c cscmatvec.cpp -o cscmatvec.o

cscmatvec: cscmatvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o
	@$(CXX) $(CXXFLAGS) cscmatvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o -o cscmatvec

bench.o: bench.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c bench.cpp -o bench.o

bench: bench.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o
	@$(CXX) $(CXXFLAGS) bench.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o -o bench

clean:
	@/bin/rm -f Matrix.o Vector.o COO.o AOSCOO.o CSCMatrix.o CSRMatrix.o amath583.o matvec.o aosmatvec.o cscmatvec.o bench.o
	@/bin/rm -f matvec aosmatvec cscmatvec bench.o

package: Makefile COO.cpp COO.hpp AOSMatrix.cpp AOSMatrix.hpp CSCMatrix.cpp CSCMatrix.hpp CSRMatrix.cpp CSRMatrix.hpp Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp amath583.cpp amath583.hpp matvec.cpp aosmatvec.cpp cscmatvec.cpp bench.cpp sampleDenseMatrix.txt sampleSparseMatrix.txt sampleVector.txt midterm.txt
	@$ tar -czf midterm.tgz Makefile COO.cpp COO.hpp AOSMatrix.cpp AOSMatrix.hpp CSCMatrix.cpp CSCMatrix.hpp CSRMatrix.cpp CSRMatrix.hpp Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp amath583.cpp amath583.hpp matvec.cpp aosmatvec.cpp cscmatvec.cpp bench.cpp sampleDenseMatrix.txt sampleSparseMatrix.txt sampleVector.txt midterm.txt
