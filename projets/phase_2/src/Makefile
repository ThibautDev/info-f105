all: main test

main: main.cpp memory.cpp
	g++ -Wall -Wextra main.cpp memory.cpp -o main

run: main
	./main ./test.txt

test: main
	python3 tests2.py ./main

clean:
	rm main