# Makefile for lab1, Bharat Kathi, CS32, S22

#CXX=clang++
CXX=g++

helloWorld: helloWorld.o
	${CXX} helloWorld.o -o helloWorld

helloWorld.o: helloWorld.cpp
	${CXX} -c helloWorld.cpp

clean:
	rm -f *.o helloWorld lab1Test

lab1Test: lab1Test.o tddFuncs.o arrayFuncs.o
	${CXX} lab1Test.o tddFuncs.o arrayFuncs.o -o lab1Test

lab1Test.o: lab1Test.cpp
	${CXX} -c lab1Test.cpp