EXEC := bin/exec

all: clean $(EXEC) test

$(EXEC): src/main.cpp src/Instruction.cpp src/Memory.cpp 
	g++ -Wall -Wextra $^ -o $@

test: $(EXEC)
	python3 ./tests3.py ./$(EXEC)

custom_test: $(EXEC)
	./$(EXEC) test.txt

clean:
	rm -f $(EXEC)