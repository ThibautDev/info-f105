all: clean compile run_test

compile: main.cpp Instruction.cpp Memory.cpp saturated.cpp
	g++ $^ -o main

run_test: main
	./main test.txt

clean:
	rm -f main
