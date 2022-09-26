c=clang++
# c=g++
vector.out: main.cpp vector.o reference.o
	$c main.cpp -o vector.out

vector.o: vector.cpp reference.o
	$c -c vector.cpp reference.o -o vector.o

reference.o:
	$ reference.cpp -c -o reference.o
