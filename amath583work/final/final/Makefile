#
# This file is part of the course materials for AMATH483/583 at the University of Washington,
# Spring 2017
#
# Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
# https://creativecommons.org/licenses/by-nc-sa/4.0/
#
# Author: Andrew Lumsdaine
# 


LANG		= -std=c++14 -Wc++14-extensions
AVX		= -fslp-vectorize-aggressive -mxsave -mavx -mavx2
ALTAVX		= -mavx -mavx2 -mxsave -mavx512cd -mavx512dq -mavx512er -mavx512f -mavx512ifma -mavx512pf -mavx512vbmi -mavx512vl
ALTOPTS		= -mfma 
PICKY		= -Wall

CXX		= c++
OPTS		= -Ofast -march=native -DNDEBUG 
REPORTING       = -Rpass=.*

CXXFLAGS	= $(OPTS) $(LANG) $(PICKY)

HEADERS		= AOS.hpp COO.hpp CSR.hpp Matrix.cpp Vector.cpp
TESTS		= testmult.cpp testvec.cpp testcsr.cpp testcoo.cpp testsparse.cpp bench.cpp cpuinfo.cpp
SOURCES		= AOS.cpp COO.cpp CSR.cpp Matrix.cpp Vector.cpp
OBJECTS		= $(SOURCES:.cpp=.o) $(TESTS:.cpp=.o)
TARGETS		= $(TESTS:.cpp=)
PCHS		= $(HEADERS:=.gch)


all		: $(TARGETS)

%.o 		: %.cpp
		  $(CXX) -c $(CXXFLAGS) $< -o $@

%.s 		: %.cpp
		  $(CXX) -S $(CXXFLAGS) $<

bench		: bench.o Matrix.o
		  $(CXX) $(CXXFLAGS) $^ -o $@ -pthread

testmult	: testmult.o Matrix.o
		  $(CXX) $(CXXFLAGS) $^ -o $@ -pthread

testvec		: testvec.o Vector.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

testcsr		: testcsr.o CSR.o Vector.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

testcoo		: testcoo.o COO.o Vector.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

testsparse	: testsparse.o CSR.o COO.o AOS.o Vector.o Matrix.o 
		  $(CXX) $(CXXFLAGS) $^ -o $@ -pthread

cpuinfo		: cpuinfo.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

defreport	:
		  $(CXX) -dM -E -x c++ /dev/null

optreport	:
		  echo 'int;' | $(CXX) -xc++ $(CXXFLAGS) - -o /dev/null -\#\#\#

clean		:
		  /bin/rm -f $(TARGETS) $(OBJECTS) $(PCHS) Matrix.s

depend		:
		  makedepend -- $(CXXFLAGS) -- $(SOURCES) $(TESTS)

# DO NOT DELETE

AOS.o: AOS.hpp Vector.hpp
COO.o: COO.hpp Vector.hpp
CSR.o: CSR.hpp Vector.hpp
Matrix.o: Matrix.hpp Vector.hpp
Vector.o: Vector.hpp
testmult.o: Matrix.hpp Vector.hpp
testvec.o: Vector.hpp
testcsr.o: Vector.hpp CSR.hpp
testcoo.o: Vector.hpp COO.hpp
testsparse.o: Vector.hpp Matrix.hpp COO.hpp CSR.hpp AOS.hpp Timer.hpp
bench.o: Matrix.hpp Vector.hpp Timer.hpp


# BEGIN CHANGE:

MPI	= mpic++ -cxx=clang++
MPIFLAGS	= -Ofast -march=native -DNDEBUG -std=c++11 -Wc++11-extensions -pthread -Wall

mpi2norm_timer.o: mpi2norm_timer.cpp Timer.hpp
	$(MPI) $(MPIFLAGS) -c mpi2norm_timer.cpp -o mpi2norm_timer.o

mpi2norm_timer: mpi2norm_timer.o Vector.o Matrix.o
	$(MPI) $(MPIFLAGS) mpi2norm_timer.o Vector.o Matrix.o -o mpi2norm_timer

thr2norm_timer.o: thr2norm_timer.cpp Timer.hpp
	$(MPI) $(MPIFLAGS) -c thr2norm_timer.cpp -o thr2norm_timer.o

thr2norm_timer: thr2norm_timer.o Vector.o Matrix.o
	$(MPI) $(MPIFLAGS) thr2norm_timer.o Vector.o Matrix.o -o thr2norm_timer

tsk2norm_timer.o: tsk2norm_timer.cpp Timer.hpp
	$(MPI) $(MPIFLAGS) -c tsk2norm_timer.cpp -o tsk2norm_timer.o

tsk2norm_timer: tsk2norm_timer.o Vector.o Matrix.o
	$(MPI) $(MPIFLAGS) tsk2norm_timer.o Vector.o Matrix.o -o tsk2norm_timer

package: amath583.cpp amath583.hpp AOS.cpp AOS.hpp bench.cpp cg.cpp cg.hpp COO.cpp COO.hpp cpuinfo.cpp CSR.cpp CSR.hpp Grid.cpp Grid.hpp ir.cpp ir.hpp Makefile Matrix.cpp Matrix.hpp mpiStencil.cpp testasync.cpp testmult.cpp testsparse.cpp testvec.cpp testcoo.cpp testcsr.cpp Stencil.cpp Stencil.hpp Timer.hpp sparsebench.cpp Vector.cpp Vector.hpp plot.py ex1.txt mpi2norm_timer.cpp thr2norm_timer.cpp tsk2norm_timer.cpp mpiTwoNormMPI.pdf mpiTwoNormOpenMP.pdf Final.cpp
	tar -czf final.tgz amath583.cpp amath583.hpp AOS.cpp AOS.hpp bench.cpp cg.cpp cg.hpp COO.cpp COO.hpp cpuinfo.cpp CSR.cpp CSR.hpp Grid.cpp Grid.hpp ir.cpp ir.hpp Makefile Matrix.cpp Matrix.hpp mpiStencil.cpp testasync.cpp testmult.cpp testsparse.cpp testvec.cpp testcoo.cpp testcsr.cpp Stencil.cpp Stencil.hpp Timer.hpp sparsebench.cpp Vector.cpp Vector.hpp plot.py ex1.txt mpi2norm_timer.cpp thr2norm_timer.cpp tsk2norm_timer.cpp mpiTwoNormMPI.pdf mpiTwoNormOpenMP.pdf Final.cpp
# END CHANGE:
