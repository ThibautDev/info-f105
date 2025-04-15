main: main.cpp Person.o
	g++ main.cpp Person.o -o main

Person.o: Person.hpp Person.cpp
		g++ -c Person.cpp -o Person.o


clean:
	rm *.o main