CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS=-std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
# Change to this before final submission:
# CXXFLAGS=-std=c++17 -Wall -Wextra -Werror

# Note that you should not use `-Wall` and `-Werror` together in production-grade code.
# Because, when switching compilers, you may get additional warnings which would turn into errors.

BINARIES=testStudent1 testStudent2 testStudent3

all: ${BINARIES}

tests: ${BINARIES}
	./testStudent1
	./testStudent2
	./testStudent3

testStudent1: testStudent1.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testStudent2: testStudent2.o Student.o tddFuncs.o
	${CXX} $^ -o $@

testStudent3: testStudent3.o Student.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o