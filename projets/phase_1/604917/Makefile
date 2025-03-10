all: main test

main: 
	g++ -Wall -Wextra main.cpp -o main

test: main
	python3 tests1.py ./main

clean:
	rm main
