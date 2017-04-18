
bench: bench.o Matrix.o
	c++ -O3 -std=c++11 -Wc++11-extensions bench.o Matrix.o -o bench

bench.o: bench.cpp Matrix.hpp
	c++ -O3 -std=c++11 -Wc++11-extensions -c bench.cpp -o bench.o

Matrix.o: Matrix.cpp Matrix.hpp
	c++ -O3 -std=c++11 -Wc++11-extensions -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp
	c++ -O3 -std=c++11 -Wc++11-extensions -Wall -c Vector.cpp -o Vector.o

clean:
	/bin/rm -f bench bench.o Matrix.o Vector.o 
