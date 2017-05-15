CXX	= c++
CL	= clang++
CLFLAGS	= -O3 -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -fopenmp -Wall
CXXFLAGS 	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -pthread -Wall

hello: hello_omp_thread.cpp hello_omp.cpp
	@$(CL) $(CLFLAGS) hello_omp_thread.cpp -o hello1.out
	@$(CL) $(CLFLAGS) hello_omp.cpp -o hello2.out

Matrix.o: Matrix.cpp Matrix.hpp
	@$(CL) $(CLFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(CL) $(CLFLAGS) -Wall -c Vector.cpp -o Vector.o

COO.o: COO.cpp COO.hpp
	@$(CL) $(CLFLAGS) -Wall -c COO.cpp -o COO.o

CSR.o: CSR.cpp CSR.hpp
	@$(CL) $(CLFLAGS) -Wall -c CSR.cpp -o CSR.o

pt2n_driver.o: pt2n_driver.cpp Timer.hpp
	@$(CL) $(CLFLAGS) -Wall -c pt2n_driver.cpp -o pt2n_driver.o

pt2n_driver: pt2n_driver.o Vector.o Matrix.o
	@$(CL) $(CLFLAGS) pt2n_driver.o Vector.o Matrix.o -o pt2n_driver

coo_driver.o: coo_driver.cpp Timer.hpp
	@$(CL) $(CLFLAGS) -Wall -c coo_driver.cpp -o coo_driver.o

coo_driver: coo_driver.o Vector.o Matrix.o COO.o
	@$(CL) $(CLFLAGS) coo_driver.o Vector.o Matrix.o COO.o -o coo_driver

csr_driver.o: csr_driver.cpp Timer.hpp
	@$(CL) $(CLFLAGS) -Wall -c csr_driver.cpp -o csr_driver.o

csr_driver: csr_driver.o Vector.o Matrix.o CSR.o
	@$(CL) $(CLFLAGS) csr_driver.o Vector.o Matrix.o CSR.o -o csr_driver

clean:
	@/bin/rm -f Matrix.o Vector.o COO.o CSR.o
	@/bin/rm -f hello1.out hello2.out 
	@/bin/rm -f pt2n_driver.o pt2n_driver coo_driver.o coo_driver csr_driver.o csr_driver
	@rm -rf try

package: Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp COO.cpp COO.hpp CSR.cpp CSR.hpp pt2n_driver.cpp coo_driver.cpp csr_driver.cpp
	@tar -czf ps6.tgz Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp COO.cpp COO.hpp CSR.cpp CSR.hpp pt2n_driver.cpp coo_driver.cpp csr_driver.cpp

try:
	@rm -rf try
	@mkdir try
	@cp ps6.tgz ./try
	@cd ./try &&	\
	tar -xzf ps6.tgz &&	\
	make pt2n_driver &&	\
	make coo_driver &&	\
	make csr_driver

tests583:
	python test_ps6.py True
