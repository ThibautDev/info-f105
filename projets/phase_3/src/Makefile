EXEC := bin/exec

all: clean $(EXEC) test

$(EXEC): src/main.cpp src/Instruction.cpp src/Memory.cpp 
	g++ -Wall -Wextra $^ -o $@

test: $(EXEC)
	python3 ./tests3.py ./$(EXEC)

clean:
	rm -f $(EXEC)