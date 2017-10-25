all: eight_puzzle

%: %.cpp
	g++ -std=c++11 $< -o eight_puzzle_solver

%: %.c
	gcc $< -o $@

clean:
	rm eight_puzzle_solver