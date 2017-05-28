MPI	= mpic++ -cxx=clang++
MPIFLAGS	= -Ofast -march=native -DNDEBUG -std=c++11 -Wall

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
	@/bin/rm -f Matrix.o Vector.o
	@/bin/rm -f a.out ring mpi2norm_driver.o mpi2norm_driver mpi2norm_timer.o mpi2norm_timer

package: Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp ring.cpp mpi2norm_driver.cpp mpi2norm_timer.cpp
	@tar -czf ps8.tgz Makefile Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp Timer.hpp ring.cpp mpi2norm_driver.cpp mpi2norm_timer.cpp


tests583:
	python test_ps8.py True
