CXX=g++
CXXFLAGS=-std=c++17 -Wall

BINARIES=lab5Test

all: ${BINARIES}

tests: ${BINARIES}
	./lab5Test

lab5Test: lab5Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o ${BINARIES}