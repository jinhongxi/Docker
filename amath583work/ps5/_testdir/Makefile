CXX	= c++
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -pthread -Wall

bonnie_and_clyde: bonnie_and_clyde.cpp
	@$(CXX) $(CXXFLAGS) bonnie_and_clyde.cpp -o bonnie_and_clyde

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c Vector.cpp -o Vector.o

pt2n_driver.o: pt2n_driver.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c pt2n_driver.cpp -o pt2n_driver.o

pt2n_driver: pt2n_driver.o Vector.o Matrix.o
	@$(CXX) $(CXXFLAGS) pt2n_driver.o Vector.o Matrix.o -o pt2n_driver

rt2n_driver.o: rt2n_driver.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c rt2n_driver.cpp -o rt2n_driver.o

rt2n_driver: rt2n_driver.o Vector.o Matrix.o
	@$(CXX) $(CXXFLAGS) rt2n_driver.o Vector.o Matrix.o -o rt2n_driver

tmv.o: tmv.cpp
	@$(CXX) $(CXXFLAGS) -Wall -c tmv.cpp -o tmv.o

tmv_driver.o: tmv_driver.cpp Timer.hpp
	@$(CXX) $(CXXFLAGS) -Wall -c tmv_driver.cpp -o tmv_driver.o

tmv_driver: tmv_driver.o Vector.o Matrix.o tmv.o
	@$(CXX) $(CXXFLAGS) tmv_driver.o Vector.o Matrix.o tmv.o -o tmv_driver

clean:
	@/bin/rm -f Matrix.o Vector.o pt2n_driver.o rt2n_driver.o tmv_driver.o tmv.o
	@/bin/rm -f midterm.tgz pt2n_driver rt2n_driver tmv_driver

package: Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp pt2n_driver.cpp rt2n_driver.cpp tmv.cpp tmv_driver.cpp ex5.txt roofline.pdf bandwidth.bmp
	@tar -czf ps5.tgz Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp pt2n_driver.cpp rt2n_driver.cpp tmv.cpp tmv_driver.cpp ex5.txt roofline.pdf bandwidth.bmp

tests583:
	python test_ps5.py True
