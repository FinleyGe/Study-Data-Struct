# TODO: change $c to your compiler.
c=clang++
# c=g++
vector.out: main.cpp vector.o reference.o
	$c main.cpp -o vector.out

vector.o: vector.cpp reference.o
	$c -c vector.cpp -o vector.o

reference.o:
	$c -c reference.cpp -o reference.o

clean:
	rm *.o *.out
