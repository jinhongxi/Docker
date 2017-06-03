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
