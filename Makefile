CC=g++
CC_FLAGS=-Wall --std=c++11
EXEC=eight_puzzle_solver.out
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o  $(EXEC)

%.o: %.cpp
	$(CC) -c -g $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
