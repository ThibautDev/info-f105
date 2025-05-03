all: clean compile run_test

compile: main.cpp Instruction.cpp Memory.cpp saturated.cpp
	g++ $^ -o main

run_test: main
	./main test.txt

run_py_test: main
	python3 ./tests3.py ./main

clean:
	rm -f main
