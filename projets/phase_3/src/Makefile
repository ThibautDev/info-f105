all: main

compile: main.cpp Instruction.cpp saturated.cpp
	g++ $^ -o main

run_test: main
	./main test.txt

clean:
	rm main