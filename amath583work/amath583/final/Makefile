#
# This file is part of the course materials for AMATH483/583 at the University of Washington,
# Spring 2017
#
# Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
# https://creativecommons.org/licenses/by-nc-sa/4.0/
#
# Author: Andrew Lumsdaine
# 

LANG		= -std=c++11 -Wc++11-extensions
AVX		=
TINYMTL		= /nfs/home/trove/amath583
INCLUDE		= -I$(TINYMTL) -I.
PICKY		= -Wall

CXX		= mpic++ -cxx=clang++
OPTS		= -Ofast -march=native -DNDEBUG $(AVX)
REPORTING	= -Rpass=.*
CPPFLAGS	+= -MD -MP

CXXFLAGS	= $(LANG) $(OPTS) $(INCLUDE) $(AVX) $(PICKY)

HEADERS		= Vector.hpp Matrix.hpp Grid.hpp Timer.hpp Stencil.hpp cg.hpp ir.hpp
FINAL		= Final.cpp mpiStencil.cpp
TESTS		= cg-seq.cpp ir-seq.cpp mpi2norm_driver.cpp ir-mpi.cpp cg-mpi.cpp
SOURCES		= Matrix.cpp Vector.cpp Grid.cpp Stencil.cpp cg.cpp ir.cpp

OBJECTS		= $(SOURCES:.cpp=.o) $(TESTS:.cpp=.o) $(FINAL:.cpp=.o)
TARGETS		= $(TESTS:.cpp=)
PCHS		= $(HEADERS:=.gch)

all		: $(TARGETS)

%.o		: %.cpp
		  $(CXX) -c $(CXXFLAGS) $< -o $@

%.s		: %.cpp
		  $(CXX) -S $(CXXFLAGS) $<

jacobi-seq	: jacobi-seq.o Grid.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

mpi2norm_driver : mpi2norm_driver.o Vector.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

cg-seq		: cg-seq.o cg.o Grid.o Stencil.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

cg-mpi		: cg-mpi.o cg.o Grid.o Stencil.o mpiStencil.o Final.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

ir-seq		: ir-seq.o ir.o Grid.o Stencil.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

ir-mpi		: ir-mpi.o ir.o Grid.o Stencil.o mpiStencil.o Final.o
		  $(CXX) $(CXXFLAGS) $^ -o $@

defreport	:
		  $(CXX) -dM -E -x c++ /dev/null

optreport	:
		  echo 'int;' | $(CXX) -xc++ $(CXXFLAGS) - -o /dev/null -\#\#\#

# DO NOT DELETE

Matrix.o: /nfs/home/trove/amath583/Matrix.hpp
Matrix.o: /nfs/home/trove/amath583/Vector.hpp
Vector.o: /nfs/home/trove/amath583/Vector.hpp
Grid.o: /nfs/home/trove/amath583/Grid.hpp
Stencil.o: /nfs/home/trove/amath583/Grid.hpp
Stencil.o: /nfs/home/trove/amath583/Stencil.hpp
cg.o: /nfs/home/trove/amath583/Grid.hpp /nfs/home/trove/amath583/Stencil.hpp
cg.o: /nfs/home/trove/amath583/cg.hpp
ir.o: /nfs/home/trove/amath583/Grid.hpp /nfs/home/trove/amath583/Stencil.hpp
ir.o: /nfs/home/trove/amath583/ir.hpp
jacobi-seq.o: /nfs/home/trove/amath583/Grid.hpp
cg-seq.o: /nfs/home/trove/amath583/Grid.hpp /nfs/home/trove/amath583/cg.hpp
cg-seq.o: /nfs/home/trove/amath583/Stencil.hpp
ir-seq.o: /nfs/home/trove/amath583/Grid.hpp
ir-seq.o: /nfs/home/trove/amath583/Stencil.hpp
ir-seq.o: /nfs/home/trove/amath583/ir.hpp
mpi2norm_driver.o: /nfs/home/trove/amath583/Timer.hpp
mpi2norm_driver.o: /nfs/home/trove/amath583/Vector.hpp
ir-mpi.o: /nfs/home/trove/amath583/Grid.hpp /nfs/home/trove/amath583/ir.hpp
ir-mpi.o: /nfs/home/trove/amath583/Stencil.hpp mpiStencil.hpp Final.hpp
cg-mpi.o: /nfs/home/trove/amath583/Grid.hpp /nfs/home/trove/amath583/cg.hpp
cg-mpi.o: /nfs/home/trove/amath583/Stencil.hpp mpiStencil.hpp Final.hpp

