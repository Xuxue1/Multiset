edit: main.o Multiset.o 
	g++ main.o Multiset.o -o test.exe
main.o :main.cpp main.h 
	g++ -c main.cpp
Multiset.o :Multiset.cpp Multiset.h
	g++ -c Multiset.cpp