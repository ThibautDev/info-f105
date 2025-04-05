all: main test

main: main.cpp
	g++ -Wall -Wextra main.cpp memory.cpp -o main

compileRun: main.cpp
	make main
	./main ./test.txt

test:
	make main
	python3 tests1.py ./main

clean:
	rm main
