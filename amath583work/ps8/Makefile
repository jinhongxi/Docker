MPI	= mpic++ -cxx=clang++
MPIFLAGS	= -O3 -march=native -DNDEBUG -std=c++11 -Wall

hello: hello.cpp
	@$(MPI) $(MPIFLAGS) hello.cpp

pid: pid.cpp
	@$(MPI) $(MPIFLAGS) pid.cpp
	@mpirun -np 4 ./a.out

pingpong: pingpong.cpp
	@$(MPI) $(MPIFLAGS) pingpong.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	@$(MPI) $(MPIFLAGS) -Wall -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp Matrix.hpp
	@$(MPI) $(MPIFLAGS) -Wall -c Vector.cpp -o Vector.o

COO.o: COO.cpp COO.hpp
	@$(MPI) $(MPIFLAGS) -Wall -c COO.cpp -o COO.o

CSR.o: CSR.cpp CSR.hpp
	@$(MPI) $(MPIFLAGS) -Wall -c CSR.cpp -o CSR.o

ring: ring.cpp
	@$(MPI) $(MPIFLAGS) ring.cpp -o ring

mpi2norm_driver.o: mpi2norm_driver.cpp
	@$(MPI) $(MPIFLAGS) -Wall -c mpi2norm_driver.cpp -o mpi2norm_driver.o

mpi2norm_driver: mpi2norm_driver.o Vector.o Matrix.o
	@$(MPI) $(MPIFLAGS) mpi2norm_driver.o Vector.o Matrix.o -o mpi2norm_driver

mpi2norm_timer.o: mpi2norm_timer.cpp Timer.hpp
	@$(MPI) $(MPIFLAGS) -Wall -c mpi2norm_timer.cpp -o mpi2norm_timer.o

mpi2norm_timer: mpi2norm_timer.o Vector.o Matrix.o
	@$(MPI) $(MPIFLAGS) mpi2norm_timer.o Vector.o Matrix.o -o mpi2norm_timer

clean:
	@/bin/rm -f Matrix.o Vector.o COO.o CSR.o
	@/bin/rm -f a.out ring mpi2norm_driver.o mpi2norm_driver mpi2norm_timer.o mpi2norm_timer
	@rm -rf try

package: Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp COO.cpp COO.hpp CSR.cpp CSR.hpp ring.cpp mpi2norm_driver.cpp mpi2norm_timer.cpp
	@tar -czf ps8.tgz Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp COO.cpp COO.hpp CSR.cpp CSR.hpp ring.cpp mpi2norm_driver.cpp mpi2norm_timer.cpp

try:
	@rm -rf try
	@mkdir try
	@cp ps8.tgz ./try
	@cd ./try &&	\
	tar -xzf ps8.tgz &&	\
	make ring &&	\
	make mpi2norm_driver &&	\
	make mpi2norm_timer

tests583:
	python test_ps8.py True
