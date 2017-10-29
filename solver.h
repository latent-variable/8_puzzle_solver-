#ifndef SOLVER_H
#define SOLVER_H
/*
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "eight_puzzle.h"
*/
using namespace std;
class eight_puzzle;

class solver{
    public:
        solver();
        solver(eight_puzzle*);
        
        void operators(eight_puzzle*);
        bool check_tree(eight_puzzle*);
        bool compare_puzzle(int*,int*);
        void push();
        
        
        //solving solutions 
        void Uniform_Cost();
        void Misplaced_tile();
        void Manhattan_distance();
    
    private:
        stack<eight_puzzle*> puzzle_stack;
        vector<eight_puzzle*> puzzle_tree;
    
};

#endif