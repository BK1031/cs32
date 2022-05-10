CXX=g++
CXXFLAGS=-std=c++17 -Wall

BINARIES=lab6Test

all: ${BINARIES}

tests: ${BINARIES}
	./lab6Test

lab6Test: lab6Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o ${BINARIES}