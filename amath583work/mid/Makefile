CXX	= c++
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -Wall

COO.o: COO.cpp COO.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c COO.cpp -o COO.o

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

amath583.o: amath583.cpp amath583.hpp Vector.hpp Matrix.hpp Timer.hpp COO.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c amath583.cpp -o amath583.o

matvec.o: matvec.cpp amath583.hpp
	@$(CXX) $(CXXFLAGS) -c matvec.cpp -o matvec.o

matvec: matvec.o amath583.o
	@$(CXX) $(CXXFLAGS) matvec.o amath583.o -o matvec

clean:
	/bin/rm -f Matrix.o Vector.o COO.o

package: Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp COO.cpp COO.hpp
	@$ tar -czf midterm.tgz Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp COO.cpp COO.hpp
