main: main.cpp Person.o
	g++ main.cpp Student.o -o main

Person.o: Student.hpp Student.cpp
		g++ -c Student.cpp -o Student.o


clean:
	rm *.o main