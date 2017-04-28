CXX	= c++
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -Wall

COO.o: COO.cpp COO.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c COO.cpp -o COO.o

AOSCOO.o: AOSMatrix.cpp AOSMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c AOSMatrix.cpp -o AOSCOO.o

CSCMatrix.o: CSCMatrix.cpp CSCMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c CSCMatrix.cpp -o CSCMatrix.o

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

amath583.o: amath583.cpp amath583.hpp Vector.hpp Matrix.hpp Timer.hpp COO.hpp AOSMatrix.hpp CSCMatrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c amath583.cpp -o amath583.o

matvec.o: matvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c matvec.cpp -o matvec.o

matvec: matvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o
	@$(CXX) $(CXXFLAGS) matvec.o amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o -o matvec
 
aosmatvec.o: aosmatvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c aosmatvec.cpp -o aosmatvec.o

aosmatvec: aosmatvec.cpp amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o
	@$(CXX) $(CXXFLAGS) aosmatvec.cpp amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o -o aosmatvec

cscmatvec.o: cscmatvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c cscmatvec.cpp -o cscmatvec.o

cscmatvec: cscmatvec.cpp amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o
	@$(CXX) $(CXXFLAGS) cscmatvec.cpp amath583.o Vector.o Matrix.o COO.o AOSCOO.o CSCMatrix.o -o cscmatvec

clean:
	@/bin/rm -f Matrix.o Vector.o COO.o AOSCOO.o CSCMatrix.o amath583.o matvec.o aosmatvec.o cscmatvec.o
	@/bin/rm -f matvec aosmatvec cscmatvec

package: Makefile COO.cpp COO.hpp AOSMatrix.cpp AOSMatrix.hpp CSCMatrix.cpp CSCMatrix.hpp Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp amath583.cpp amath583.hpp matvec.cpp aosmatvec.cpp cscmatvec.cpp sampleDenseMatrix.txt sampleSparseMatrix.txt sampleVector.txt midterm.txt
	@$ tar -czf midterm.tgz Makefile COO.cpp COO.hpp AOSMatrix.cpp AOSMatrix.hpp CSCMatrix.cpp CSCMatrix.hpp Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp amath583.cpp amath583.hpp matvec.cpp aosmatvec.cpp cscmatvec.cpp sampleDenseMatrix.txt sampleSparseMatrix.txt sampleVector.txt midterm.txt
