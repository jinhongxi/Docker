CXX	= c++
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -pthread -Wall

bonnie_and_clyde: bonnie_and_clyde.cpp
	@$(CXX) $(CXXFLAGS) bonnie_and_clyde.cpp -o bonnie_and_clyde

pi: pi.cpp
	@$(CXX) $(CXXFLAGS) pi.cpp -o pi

try33.o: try33.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c try33.cpp -o try33.o

try33: try33.o Vector.o Matrix.o
	@$(CXX) $(CXXFLAGS) try33.o Vector.o Matrix.o -o try33

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

ptn2_driver.o: ptn2_driver.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c ptn2_driver.cpp -o ptn2_driver.o

ptn2_driver: ptn2_driver.o Vector.o Matrix.o
	@$(CXX) $(CXXFLAGS) ptn2_driver.o Vector.o Matrix.o -o ptn2_driver

rtn2_driver.o: rtn2_driver.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c rtn2_driver.cpp -o rtn2_driver.o

rtn2_driver: rtn2_driver.o Vector.o Matrix.o
	@$(CXX) $(CXXFLAGS) ptn2_driver.o Vector.o Matrix.o -o rtn2_driver

tmv.o: tmv.cpp
	@$(CXX) $(CXXFLAGS) -Wall -c tmv.cpp -o tmv.o

tmv_driver.o: tmv_driver.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c tmv_driver.cpp -o tmv_driver.o

tmv_driver: tmv_driver.o Vector.o Matrix.o
	@$(CXX) $(CXXFLAGS) tmv_driver.o Vector.o Matrix.o -o tmv_driver

clean:
	@/bin/rm -f Matrix.o Vector.o ptn2_driver.o rtn2_driver.o tmv_driver.o tmv.o try32.o try33.o
	@/bin/rm -f midterm.tgz ptn2_driver rtn2_driver tmv_driver bonnie_and_clyde pi try32 try33

package: Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp ptn2_driver.cpp rtn2_driver.cpp tmv_driver.cpp ex5.txt
	@tar -czf ps5.tgz Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp ptn2_driver.cpp rtn2_driver.cpp tmv_driver.cpp ex5.txt

tests583:
	python test_ps5.py True
