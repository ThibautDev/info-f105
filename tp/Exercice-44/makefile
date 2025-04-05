main: main.cpp fctAdd.cpp
	g++ -c main.cpp -o main.o
	g++ -c fctAdd.cpp -o fctAdd.o
	g++ $^ -o $@

exec: main
	./$^

clean: main main.o fctAdd.o
	rm $^